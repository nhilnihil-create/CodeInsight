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
    int n;
    cin >> n;
    vector<int> a(n), b(n), c(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        a[i]--;
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }
    for (int i = 0; i < n-1; ++i) {
        cin >> c[i];
    }

    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += b[a[i]];
        if (i >= 1 && a[i] == a[i-1] + 1) res += c[a[i-1]];
    }
    cout << res << endl;
}