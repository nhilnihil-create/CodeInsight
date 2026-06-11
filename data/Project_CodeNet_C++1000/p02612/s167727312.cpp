#include <cstdio>
int main(){
    int n;scanf("%d",&n);
    for(int i=1;;i++) if(i*1000>=n) return printf("%d\n",i*1000-n),0;
}