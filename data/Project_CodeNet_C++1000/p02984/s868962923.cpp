#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define fi first
#define se second
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF = (1<<30) - 1;
const ll LINF = (1LL<<60) - 1;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    vector<ll> res(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        if (i % 2) res[0] -= a[i];
        else res[0] += a[i];
    }

    for (int i = 1; i < n; ++i) {
        res[i] = -res[i-1] + a[i-1] * 2;
    }
    for (int i = 0; i < n; ++i) {
        if (i < n-1) cout << res[i] << " ";
        else cout << res[i] << endl;
    }
}