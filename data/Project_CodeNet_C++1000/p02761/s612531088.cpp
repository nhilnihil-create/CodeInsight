#include <bits/stdc++.h>
#define all(v) (v).begin(), (v).end()
#define pb push_back
#define REP(i,n) for(int i=0; i<(n); i++)
#define REP2(i,x,n) for(int i=x; i<(n); i++)
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
template<class T>using numr=std::numeric_limits<T>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const int INF = 1e9;
const ll LLINF = 1e16;
const int MOD = 1000000007;
const int MOD2 = 998244353;

int main() {
    int N, M;
    cin >> N >> M;
    vector< int > t(N, -1);
    for(int i = 0; i < M; i++) {
        int k, x;
        cin >> k >> x;
        --k;
        if(t[k] == -1 || t[k] == x) {
        t[k] = x;
        } else {
        cout << -1 << endl;
        return 0;
        }
    }
    if(N == 1) {
        for(auto &x : t) cout << max(x, 0);
        cout << endl;
    } else {
        if(t[0] == 0) {
        cout << -1 << endl;
        return 0;
        }
        if(t[0] == -1) t[0] = 1;
        for(auto &x : t) cout << max(x, 0);
        cout << endl;
    }
}