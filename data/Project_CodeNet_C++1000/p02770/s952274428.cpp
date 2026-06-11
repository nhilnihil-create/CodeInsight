#include <bits/stdc++.h>
#define N 5005
typedef long long ll;
using namespace std;

ll d[N],dd[N];

int main(){
    ll k,q;
    scanf("%lld%lld",&k,&q);
    for(ll i=1;i<=k;i++) scanf("%lld",&dd[i]);
    while(q--){
        ll n,x,m;
        scanf("%lld%lld%lld",&n,&x,&m);
        n--;
        ll sum=0; ll cnt=0;
        for(ll i=1;i<=k;i++){
            d[i]=dd[i]%m;
            if(d[i]==0) cnt++;
            sum+=d[i];
        }
        cnt*=n/k; sum*=n/k; sum+=x%m;
        for(ll i=1;i<=n%k;i++){
            if(d[i]==0) cnt++;
            sum+=d[i];
        }
        //cout<<cnt<<" "<<sum<<endl;
        printf("%lld\n",n-cnt-sum/m);
    }
}
