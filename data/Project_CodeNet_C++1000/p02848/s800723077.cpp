#include <stdio.h>
#include <string.h>
 
int main (){
 
    int n;
    scanf("%d", &n);
    char arr[10000];
    scanf("%s", arr);
    for(int i = 0; i < strlen(arr); i++){
        arr[i] = arr[i] + n;
        if(arr[i] >= 91) arr[i] -= 26;
    }
 
    printf("%s", arr);
 
 	return 0;
}