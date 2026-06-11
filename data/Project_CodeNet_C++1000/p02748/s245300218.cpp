#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define REP(i,n) for (ll i = 0; i < (n); ++i)
#define RREP(i, n) for (ll i = (n) - 1; i >= 0; --i)
#define ALL(v) (v).begin(), (v).end()
template<class T>
using reverse_priority_queue = priority_queue<T, vector<T>, greater<T>>;


int main(){
    ll a, b, m;
    cin >> a >> b >> m;
    vector<ll> pa(a), pb(b);
    REP(i, a){ cin >> pa.at(i); }
    REP(i, b){ cin >> pb.at(i); }
    ll ans = *min_element(ALL(pa)) + *min_element(ALL(pb));
    REP(i, m){
        ll xi, yi, ci;
        cin >> xi >> yi >> ci;
        xi--; yi--;
        ans = min(ans, pa.at(xi) + pb.at(yi) - ci);
    }
    cout << ans << endl;
    return 0;
}
