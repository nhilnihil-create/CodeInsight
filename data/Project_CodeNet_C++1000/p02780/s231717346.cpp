#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n, k;
    cin >> n >> k;
    vector<int> p(n);
    vector<double> e(n+1, 0);
    for (int i = 0; i < n; ++i) {
        cin >> p[i];
        e[i+1] = (double)(p[i] + 1) / 2.0;
    }
    for (int i = 0; i < n; ++i) {
        e[i+1] += e[i];
    }

    double res = 0;
    for (int i = k; i <= n; ++i) {
        chmax(res, e[i] - e[i-k]);
    }
    cout << fixed << setprecision(12) << res << endl;
}