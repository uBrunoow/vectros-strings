#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool validateCPF(char *strCPF) {
    char cpf[12];
    int j = 0, sum = 0, remainder, i;
    
    for (i = 0; strCPF[i] != '\0'; i++) {
        if (strCPF[i] >= '0' && strCPF[i] <= '9') {
            cpf[j++] = strCPF[i];
        }
    }
    cpf[j] = '\0';
    
    if (strlen(cpf) != 11) {
        return false;
    }
    
    if (strcmp(cpf, "00000000000") == 0 || strcmp(cpf, "11111111111") == 0 ||
        strcmp(cpf, "22222222222") == 0 || strcmp(cpf, "33333333333") == 0 ||
        strcmp(cpf, "44444444444") == 0 || strcmp(cpf, "55555555555") == 0 ||
        strcmp(cpf, "66666666666") == 0 || strcmp(cpf, "77777777777") == 0 ||
        strcmp(cpf, "88888888888") == 0 || strcmp(cpf, "99999999999") == 0) {
        return false;
    }
    
    for (i = 0; i < 9; i++) {
        sum += (cpf[i] - '0') * (10 - i);
    }
    remainder = (sum * 10) % 11;
    if (remainder == 10 || remainder == 11) {
        remainder = 0;
    }
    if (remainder != (cpf[9] - '0')) {
        return false;
    }
    
    sum = 0;
    for (i = 0; i < 10; i++) {
        sum += (cpf[i] - '0') * (11 - i);
    }
    remainder = (sum * 10) % 11;
    if (remainder == 10 || remainder == 11) {
        remainder = 0;
    }
    if (remainder != (cpf[10] - '0')) {
        return false;
    }
    
    return true;
}

int main() {
    char cpf[15];

    printf("Insira um CPF (formato XXX.XXX.XXX-XX): ");
    scanf("%14s", cpf);
    if (validateCPF(cpf)) {
        printf("CPF é válido.\n");
        printf("Desenvolvedor do Programa: Bruno Werner");
    } else {
        printf("CPF é inválido.\n");
    }
    return 0;
}