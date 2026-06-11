#include <bits/stdc++.h>
#define be(v) (v).begin(),(v).end()
#define pb(q) push_back(q)
typedef long long ll;
using namespace std;
const ll mod=1000000007, INF=(1LL<<60);
#define doublecout(a) cout<<fixed<<setprecision(10)<<a<<endl;

vector<vector<ll> > v;
int main() {
    cin.tie(0);
    cout.tie(0);
    ios::sync_with_stdio(false);
    ll n, m;
    cin >> n >> m;
    vector<ll> h(n);
    for(int i=0;i<n;i++) cin>> h[i];
    v.resize(n);
    ll a,b ;
    for(int i=0;i<m;i++){
        cin >> a >> b;
        a--; b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    ll ans = 0;
    for(int i=0;i<n;i++){
        bool maki = true;
        for(auto& j: v[i]){
            if(h[j] >= h[i]) maki = false;
        }
        if(maki) ans++;
    }
    cout << ans << endl;
    return 0;
}
