#include <string.h>
#include <stdio.h>
int main (){
     int k;
     int pan;
     char s[101];
     scanf("%d",&k);
     scanf("%s",&s);
     pan = strlen (s);

     if (pan <= k){
         printf("%s",s);
    }
    else if (pan> k ){
        for (int i=0; i <= k-1; i++){
            printf("%c",s[i]);
        }
        printf("...");
    }
return 0;
}