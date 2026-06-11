#include <stdio.h>
int main(){
    int n, i, s, g;
    for(i=1, g=1; i <10;i++){
             printf("%dx%d=%d\n", g,i, g*i);
             if(i==9){
             i=0;
             g++;         
             }
             if(g==10)
             break;
             }
    return 0;
    }