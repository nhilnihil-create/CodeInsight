#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
#define rep(i, n) for(int i = 0; i < n; i++)
#define REP(i, a, b) for(int i = a; i < b; i++)
#define all(x) x.begin(), x.end()
#define fi first
#define se second
#define pb push_back
#define debug(x) cerr <<__LINE__<< ": " << #x << " = " << x << endl
#define debug_vec(v) cerr<<__LINE__<<": "<<#v<<" = ";rep(i,v.size())cerr<<" "<<v[i];cerr<<endl
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

void solve() {
    ll k, cnt = 0;
    cin >> k;
    queue<ll> que;
    REP(i, 1, 10) que.push(i);
    while(1) {
        cnt++;
        ll x = que.front();
        que.pop();
        if (cnt == k) {
            cout << x << endl;
            return;
        }
        if (x % 10 == 0) {
            que.push(x * 10 + 0);
            que.push(x * 10 + 1);
        } else if (x % 10 == 9) {
            que.push(x * 10 + 8);
            que.push(x * 10 + 9);
        } else {
            que.push(x * 10 + x % 10 - 1);
            que.push(x * 10 + x % 10);
            que.push(x * 10 + x % 10 + 1);
        }
    }
}

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    solve();
    return 0;
}
