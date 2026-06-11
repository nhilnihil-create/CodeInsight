#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int maxn = 1e4+10;

ll arr[maxn];
int K,Q,n,x,m;
ll sum[maxn],zero[maxn];
ll fun(){
    x%=m;
    ll cnt = n-1;
    for(int i = 1;i<=K;i++){
        sum[i] = sum[i-1] + arr[i]%m;
        zero[i] = zero[i-1] + (arr[i]%m == 0);
    }
    ll cnt1 = (n-1)/K*zero[K]+zero[(n-1)%K];
    ll cnt2 = ((n-1)/K*sum[K]+sum[(n-1)%K] + x )/m;
    return cnt-cnt1-cnt2;
}
int main(){
    cin>>K>>Q;
    for(int i = 1;i<=K;i++) scanf("%lld",&arr[i]);
    while(Q--){
        scanf("%d%d%d",&n,&x,&m);
        printf("%lld\n",fun());
    }

    return 0;
}