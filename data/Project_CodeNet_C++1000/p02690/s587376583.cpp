#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(ll i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr <<__LINE__<< ": " << #x << " -> " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" -> ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    ll x;
    cin >> x;
    REP(i, -200, 201) REP(j, -200, 201) {
        if (pow(i, 5) - pow(j, 5) == x) {
            cout << i << " " << j << endl;
            return;
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
