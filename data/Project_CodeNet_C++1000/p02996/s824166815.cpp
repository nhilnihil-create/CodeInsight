#include <bits/stdc++.h>
 
#define rep(i,n) for(ll i=0;i<n;++i)
#define all_map(itr,mp) for(auto itr=mp.begin();itr!=mp.end();itr++)
#define ALL(a) (a).begin(),(a).end()

using namespace std;
using ll  = long long;
using pll = pair<ll, ll>;

const ll MOD  = 1e9 + 7;
const ll LINF = 1LL << 62;
const int INF = 1e9 + 7;

int main(){
    ll n;
    cin >> n;

    vector<ll> a(n), b(n);
    rep(i, n)cin >> a[i] >> b[i];

    vector<ll> ord(n);
    iota(ALL(ord), 0);
    sort(ALL(ord), [&](ll x, ll y){
        return b[x] < b[y];
    });

    ll time = 0;
    rep(i, n){
        ll pos = ord[i];

        time += a[pos];

        if(time > b[pos]){
            cout << "No\n";
            return 0;
        }
    }

    cout << "Yes\n";
}