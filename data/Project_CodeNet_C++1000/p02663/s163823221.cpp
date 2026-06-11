#include<cstdio>

int main(){
    int h1,m1,h2,m2,k;
    scanf("%d%d%d%d%d",&h1,&m1,&h2,&m2,&k);
    int t1 = h1*60+m1, t2 = h2*60+m2;
    int dt = t2-t1;
    if(dt<k) printf("0\n");
    else{
        int start = t2-k;
        printf("%d\n",start-t1);
    }
    return 0;
}
