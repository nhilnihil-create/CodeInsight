#include <cstdio>




int main(){
    int N,R;

    scanf("%d%d",&N,&R);
    int ans=0;
    while (N){
        ans++;
        N=N/R;
    }

    printf("%d\n",ans);

    return 0;
}