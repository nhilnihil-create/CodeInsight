#include <stdio.h>
int main()
{
    int a ;
    scanf("%d",&a);
    
    int b;
    scanf("%d",&b);
    
    int c = a*500;
    
    if( c>=b){
        printf("Yes");

    }
    
    else{
        printf("No");
    }

    return 0;
}