#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 1000000;
ll mod = INF;


int main(){
    ll n;
    ll ans=0;
    cin >> n;
    for(ll a=1;a<=n;a++){
        ans+=(n-1)/a;
    }

    cout << ans<<endl;
    return 0;
}