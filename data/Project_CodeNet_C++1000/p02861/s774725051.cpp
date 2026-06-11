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

int fac(int n) {
    int res = 1;
    for (int i = 0; i < n; ++i) {
        res *= (i+1);
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    vector<int> x(n), y(n);
    for (int i = 0; i < n; ++i) {
        cin >> x[i] >> y[i];
    }

    double res = 0;
    for (int i = 0; i < n-1; ++i) {
        for (int j = i+1; j < n; ++j) {
            res += (double)fac(n-1) * 2 * sqrt((x[j] - x[i]) * (x[j] - x[i]) + (y[j] - y[i]) * (y[j] - y[i]));
        }
    }
    cout << fixed << setprecision(10) << res / (double)fac(n) << endl;
}