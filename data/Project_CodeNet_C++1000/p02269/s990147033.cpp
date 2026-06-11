#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TABLE_SIZE 16777216
#define ORDER_LENGTH 7
#define STR_LENGTH 13

using namespace std;

int array[128];

int translateStr(char buf[]){
    int sum = -1,mult = 1;
    for(int i = 0; buf[i] != '\0'; i++){
        sum += array[buf[i]]*mult;
        mult *= 4;
    }
    return sum;
}

int main(){

    array['A']=1,array['C']=2,array['G']=3,array['T']=4;

    int n;
    scanf("%d",&n);
    char order[ORDER_LENGTH],str[STR_LENGTH];

    char* check_table = new char[TABLE_SIZE];

    for(int i = 0; i < n; i++){
        scanf("%s %s",order,str);
        if(order[0] == 'i'){
            check_table[translateStr(str)] = 'Y';
        }else{
            if(check_table[translateStr(str)] == 'Y'){
                printf("yes\n");
            }else{
                printf("no\n");
            }
        }
    }
}