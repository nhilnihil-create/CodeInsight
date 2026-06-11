#include <stdio.h>

int main(){
    int a;
    char c[10000];
    scanf("%d",&a);
    getchar();
    
    scanf("%[^\n]", c);
    
    for (int i=0; c[i]!='\0'; i++){
        if(c[i]>='A' && c[i]<='Z'){
            c[i]+=a;
            if(c[i]>90){
                c[i]-=26;
            }
            printf("%c",c[i]);
        }
    }
return 0;
}