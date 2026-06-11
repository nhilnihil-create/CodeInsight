#include <bits/stdc++.h>
#define rep(i,n) for(ll i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define dunk(a) cout << (a) << endl
#define rall(a) (a).rbegin(),(a).rend()
const int INF = 2e9;
using namespace std;
using Graph = vector<vector<int>>;
typedef pair<int,int> P;
typedef long long ll;

int main(){
    int k, q; cin >> k >> q;
    vector<ll> d(k);
    rep(i,k){
        cin >> d[i];
    }

    rep(a,q){
        int n, x, m; cin >> n  >> x >> m;
        vector<ll> e(k);
        ll ans = 0;
        ll sume = 0;

        rep(i,k){
            e[i] = d[i] % m;
            sume += e[i];

            if(e[i] == 0) ans ++;

        }

        ll y = x+ (n-1)/k *sume;
        ans *= (n-1)/k;

        rep(i,(n-1)%k){
            y += e[i];

            if(e[i] == 0) ans++;

        }

        ll ans2 = (y/m - x/m);

        dunk(n - ans - ans2 - 1);

    }
}