#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll n,k;
    cin>>n>>k;

    ll ans=0;
    ll sum=n*(n+1)/2;
    for(ll i=k;i<=n+1;i++){
        ll mi=(i-1)*i/2;
        ll ma=sum-(n-i)*(n-i+1)/2;
        ll tmp=ma-mi+1;
        ans=(ans+tmp)%MOD;
    }

    cout<<ans<<endl;
}