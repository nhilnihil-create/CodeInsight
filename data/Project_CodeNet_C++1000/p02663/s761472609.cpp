#include <stdio.h>
int main(){
    int h1,m1,h2,m2,k;
    int time1,time2;
    scanf("%d %d %d %d %d",&h1,&m1,&h2,&m2,&k);
    time1=h1*60+m1;
    time2=h2*60+m2;
    time2-=time1;
    if(time2<0) time2+=12*60;
    printf("%d\n",time2-k);
}