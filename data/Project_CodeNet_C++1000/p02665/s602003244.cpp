#include<cstdio>
#include<algorithm>
using namespace std;
int n, w[101000];
long long C[101000], INF = 1e15, S[101000], res;
int main(){
    int i;
    scanf("%d",&n);
    for(i=0;i<=n;i++){
        scanf("%d",&w[i]);
    }
    C[0]=1-w[0];
    for(i=1;i<=n;i++){
        C[i]=min(C[i-1]*2-w[i],INF);
    }
    for(i=0;i<=n;i++){
        if(C[i]<0){
            puts("-1");
            return 0;
        }
    }
    S[n]=w[n];
    for(i=n-1;i>=0;i--){
        S[i] = min(C[i],S[i+1])+w[i];
    }
    for(i=0;i<=n;i++){
        res+=S[i];
    }
    printf("%lld\n",res);
}
