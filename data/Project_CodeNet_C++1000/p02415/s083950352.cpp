#include <stdio.h>


int main(){
    char s[1300];
    
    gets(s);
    for (char *p=s; *p!='\0'; p++){
        if (*p >='a' && *p <= 'z'){
            printf("%c", *p-'a'+'A');
        } else if (*p >='A' && *p <= 'Z'){
            printf("%c", *p-'A'+'a');
        } else {
            printf("%c", *p);
        }
    }
    printf("\n");   

    return 0;
}