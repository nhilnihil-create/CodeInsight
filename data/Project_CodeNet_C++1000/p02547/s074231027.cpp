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
    vector<int> a(n), b(n);
    REP(i, n) cin >> a[i] >> b[i];

    bool res = false;

    for(int i = 0; i < n; i++) {
        if (i+2 > n-1) break;

        if (a[i] == b[i] && a[i+1] == b[i+1] && a[i+2] == b[i+2]) {
            res = true;
        }
    }
    
    cout << (res ? "Yes" : "No") << endl;

    return 0;
}