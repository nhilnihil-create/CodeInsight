#include <cstdio>

int main(){
    int n;
    scanf("%d",&n);
    n=1000-n%1000;
    if(n==1000) n=0;
    printf("%d\n",n);
    
    return 0;
}
