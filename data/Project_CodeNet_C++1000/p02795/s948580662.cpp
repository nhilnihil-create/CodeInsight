#include<cstdio>

int main(){
    int h,w,n;
    scanf("%d%d%d",&h,&w,&n);
    int c = h>w?h:w;
    int time = n/(c);
    if(n%c) time++;
    printf("%d\n",time);
    return 0;
}
