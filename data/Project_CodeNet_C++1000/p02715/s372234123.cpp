#include <iostream>
#define int64 long long int
using namespace std;
const int mod = 1e9+7 , MAX = 400009 ;
int64 cnt[MAX] ;
int expo(int a,int n){
    int ret=1;
    while(n>0){
        if(n&1)  ret = (1LL * ret * a)%mod ;
        a = (1LL *a * a)%mod ;
        n>>=1;
    }
    return ret;
}
int main(){
    int n , k  ;
    scanf("%d%d",&n,&k);
    int64 ret =0  ;
    for(int i=k;i;i--){
        cnt[i] = expo(k/i,n);
        for(int j=i+i;j<=k;j+=i){
            cnt[i] += mod-cnt[j];
            cnt[i] %= mod ;
        }
        ret += (1LL * i * cnt[i]);
        ret %= mod ;
    }
    printf("%lld\n",ret);
}