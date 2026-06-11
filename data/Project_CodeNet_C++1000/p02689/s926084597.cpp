#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9+7;
int main() {
    ll n,m;
    cin >> n >> m;
    vector<ll>h(n);
    for(ll i=0;i<n;i++){
        cin >> h[i];
    }
    vector<ll>g(n,1);
    for(ll i=0;i<m;i++){
        ll a,b;
        cin >> a >> b;
        a--;
        b--;
        if(h[a]<=h[b]) g[a]=0;
        if(h[b]<=h[a]) g[b]=0;
    }
    ll cnt=0;
    for(ll i=0;i<n;i++){
        cnt+=g[i];
    }
    cout << cnt << endl;
}