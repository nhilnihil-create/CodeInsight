#include <stdio.h>
#include <string.h>

int main(){

    int brpBanyak;
    scanf("%d", &brpBanyak);
    char arrKata[brpBanyak+1];
    char kataPertama[100];
    char kataKedua[100];
    scanf("%s", arrKata);
    if(brpBanyak%2==0){
/*        for(int i=0;i<(brpBanyak/2);i++){
            kataPertama[i]=arrKata[i];
        }
        printf("dan ini kata pertama %s\n", kataPertama);
        int pasangan=(brpBanyak/2);
        for(int j=0;j<(brpBanyak/2);j++){
            kataKedua[j]=arrKata[pasangan];
            printf("ini bawah ke %d\n", j);
            pasangan++;
        }
        printf("dan ini kata kedua %s\n", kataKedua);
        if (strcmp(kataPertama, kataKedua)==0){
            printf("Yes\n");
        }
        else{
            printf("No\n");
        }
    }
    else{
        printf("No\n");
    }
*/  int j=0;
    int flag=0;
    for(int i=(brpBanyak/2);i<brpBanyak;i++){
        if(arrKata[i]!=arrKata[j]){
            printf("No\n");
            flag++;
            break;
        }
        j++;
    }
    if(flag==0){
    printf("Yes\n");
    }
    }
    else{
        printf("No\n");
    }


    return 0;   
}