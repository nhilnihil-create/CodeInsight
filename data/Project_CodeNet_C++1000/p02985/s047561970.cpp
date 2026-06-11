#include <bits/stdc++.h>
#define rep(i, n) for(int i=0; i<(n); ++i)
#define rep2(i, s, n) for(int i=s; i<(n); ++i)
#define ALL(v) (v).begin(), (v).end()

using namespace std;

typedef long long ll;

static const int INTINF = (2147483647);
static const ll LLINF = (9223372036854775807);
static const int MAX = 1e5+1;
static const ll MOD = 1e9+7;

namespace Printer{
    template<class T>
    void print(T x){
        cout << x << endl;
    }

    template<class T>
    void print(T x, T y){
        cout << x << "," << y << endl;
    }

    template<class T>
    void print(vector<T> v){
        rep(i, v.size()){
            if(i) cout << " ";
            cout<< v[i];
        }
        cout << endl;
    }

    template<class T>
    void print(vector<vector<T> > vv){
        rep(i, vv.size()){
            rep(j, vv[i].size()){
                if(j) cout << " ";
                cout << vv[i][j];
            }
            cout << endl;
        }
    }

    void print(pair<int, int> p){
        cout << "(" << p.first << ", " << p.second << ")" << endl;
    }
};
using namespace Printer;

//--global--//


ll n, k;
vector<vector<ll> > vv(MAX);
ll ans = 1;

//----------//

ll solve(ll children, ll col, ll v, ll bef){
    bool ok = false;
    for(ll u : vv[v]){
        if(u != bef) ok = true;
    }
    if(!ok){
        ans = ans * col % MOD;
        return col;
    }

    ll res = col;
    if(children < 2) children++;
    int num = 0;
    for(ll u : vv[v]){
        if(u == bef) continue;
        //cout << u << endl;
        res = res * solve(children, (k-children-num), u, v) % MOD;
        num++;
    }

    return res;
}

int main(int argc, const char * argv[]) {
    //提出時、消す----//
    //--------------//

    cin >> n >> k;
    rep(i, n-1){
        ll a, b;
        cin >> a >> b;
        a--; b--;
        vv[a].push_back(b);
        vv[b].push_back(a);
    }

    cout << solve(0, k, 0, -1) << endl;
    //cout << ans << endl;
    
    return 0;
}
