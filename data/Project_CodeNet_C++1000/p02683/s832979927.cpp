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

    int n, m, x;
    cin >> n >> m >> x;
    vector<int> c(n);
    vector<vector<int>> A(n, vector<int> (m));
    
    REP(i, n) {
        cin >> c[i];
        REP(j, m) {
            cin >> A[i][j];
        }
    }

    int cost = 1e9;

    for (int bit = 0; bit < (1 << n); bit++) {

        vector<int> sum(m, 0);
        int cost_tmp = 0;

        for (int i = 0; i < n; i++) {
            if (bit & (1 << i)) {
                cost_tmp += c[i];
                REP(j, m) {
                    sum[j] += A[i][j];
                }
            }
        }

        bool can = 1;
        for(int i = 0; i < m; i++) {
            if(sum[i] < x) can = 0;
        }
        
        if (can) cost = min(cost, cost_tmp);
    }

    if (cost == 1e9) {
        cout << -1 << endl;
    } else {
        cout << cost << endl;
    }



    return 0;
}