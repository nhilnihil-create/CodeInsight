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

    int n;
    cin >> n;
    ll res = 0;

    vector<vector<ll>> num(10, vector<ll>(10, 0));

    for(int i = 1; i <= n; i++) {
        vector<int> d;
        int ni = i;
        while (ni) {
            d.push_back(ni % 10);
            ni /= 10;
        }
        int a = d[0];
        int b = d.back();
        if (!a || !b) continue;
        num[a][b]++;
    }

    for(int i = 1; i < 10; i++) {
        for(int j = 1; j < 10; j++) {
            res += num[i][j]*num[j][i];
        }
    }

    cout << res << endl;

    return 0;
}