#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define INF 1e9+7
#define rep(i,n) for(ll i=0;i<n;i++)
#define pii pair<int,int>
#define pll pair<ll,ll>
const int maxn = 200000;
ll mod = INF;


int main(){

    ll n;
    ll h[maxn];
    ll k;
    cin >> n>>k;
    rep(i,n)cin >> h[i];
    sort(h,h+n);
    ll ans=0;
    rep(i,n-k)ans+=h[i];
    cout << ans<<endl;
    return 0;
}