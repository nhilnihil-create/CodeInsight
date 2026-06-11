#include <stdio.h>
int main (){
    int a,b,v;
    scanf ("%d",&v);
    scanf ("%d %d", &a,&b);
    for (int i=a ; i<=b ; i++)
    {
        if (i%v==0){
        printf("OK");
        return 0;    
        }
        else {
        }
    }
    printf("NG");
return 0;
}