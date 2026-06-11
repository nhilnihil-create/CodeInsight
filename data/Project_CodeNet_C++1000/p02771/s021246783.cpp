#include  <stdio.h>

int main()
{
    int a,b,c;
    scanf("%d %d %d", &a, &b, &c);
    
    if(a==b && b!=c){
        printf("Yes\n");
}
    else if(a==c && b!=a){
        printf("Yes\n");
}
    else if(b==c && a!=b){
        printf("Yes\n");
}
    else{
        printf("No\n");
}   
    return 0;
}