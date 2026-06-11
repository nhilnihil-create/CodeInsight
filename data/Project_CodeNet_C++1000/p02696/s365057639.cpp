#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(int i = 0; i < (n); i++)
#define all(v) v.begin(), v.end()
#define MOD 1000000007
const int INF = 1LL<<30;

int main(){
    ll a,b,n;
    cin>>a>>b>>n;
    ll ans=0;
    for(ll i=0;i<=min(3*a,n);i++){
        ll tmp=(a*i)/b-a*(i/b);
        ans=max(ans,tmp);
    }
    if(n>=b-1) ans=max(ans,(a*(b-1))/b-a*((b-1)/b));
    else ans=max(ans,(a*n)/b-a*(n/b));
    cout<<ans<<endl;
}