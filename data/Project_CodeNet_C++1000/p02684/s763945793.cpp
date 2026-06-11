#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); i++)
#define RREP(i, s, n) for (int i = s; i < (n); i++)
#define ALL(a) a.begin(), a.end()
#define RALL(a) a.rbegin(), a.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using namespace std;
using ll = long long;
typedef pair<int, int> pint;
typedef pair<ll, ll> pll;
const ll MOD = 1000000007;
const ll INF = MOD * MOD;
const int inf = (1<<29);

int main() {

    ll n, k;
    cin >> n >> k;
    
    vector<vector<int>> next(60, vector<int>(n));
    for(int v = 0; v < n; v++) {
        cin >> next[0][v]; next[0][v]--;
    }

    for(int d = 0; d+1 < 60; d++) {
        for(int v = 0; v < n; v++) {
            next[d+1][v] = next[d][next[d][v]];
        }
    }

    int v = 0;
    for(int d = 0; d < 60; d++) {
        if (k & (1L<<d)) v = next[d][v];
    }

    cout << v+1 << endl;

return 0;
}