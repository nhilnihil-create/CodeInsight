#include <cstdio>

int main(){
    char str[1500];

    for (int i = 0; i < 1500; i++){
        str[i] = '\0';
    }

    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++){
        if (str[i] >= 'A' && str[i] <= 'Z'){
            str[i] += 'a' - 'A';
        }
        else if (str[i] >= 'a' && str[i] <= 'z'){
            str[i] -= 'a' - 'A';
        }
    }
    printf("%s", str);

    return 0;
}