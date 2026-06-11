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

    int n, x, y;
    cin >> n >> x >> y;

    vector<int> res(n-1, 0);

    int dis;

    for(int i = 1; i <= n; i++) {
        for(int j = i+1; j <= n; j++) {
            dis = min(j-i, min(abs(x-i)+1+abs(y-j), abs(x-j)+1+abs(y-i)));
            res[dis-1]++;
        }
    }

    REP(i, n-1) {
        cout << res[i] << endl;
        
    }

    //cout << ans << endl;
    return 0;
}