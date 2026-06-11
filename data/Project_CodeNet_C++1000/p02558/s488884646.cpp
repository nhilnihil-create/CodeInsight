#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main(){
    ll n, q;
    cin >> n >> q;

    dsu d(n);
    REP(_, q){
        ll t, u, v;
        cin >> t >> u >> v;
        if(t == 0){
            d.merge(u, v);
        }else{
            cout << (int)(d.same(u, v)) << endl;
        }
    }
    return 0;
}
