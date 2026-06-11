#include <stdio.h>
int main(){
    int num;
    scanf("%d", &num);
    int count = 0;
    if(num % 2 == 1){//jika panjang str tdk bisa dibagi 2, maka langsung return 0
        printf("No\n");
        return 0;
    }
    char str[num];
    scanf("%s", str);
    for(int i = 0; str[i] != '\0'; i++){
        if(str[i] == str[(num / 2) + i]){//kasus jika ada 6 huruf
            count++;//untuk mengecek huruf pertama dan ke empat sama gak
        }
    }
    if(count == num / 2){//jika counter == panjang str / 2
        printf("Yes\n");
    }else{
        printf("No\n");
    }
    return 0;
}