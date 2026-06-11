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
    vector<ll> a(n+1), b(n);
    for (int i = 0; i < n+1; ++i) {
        cin >> a[i];
    }
    for (int i = 0; i < n; ++i) {
        cin >> b[i];
    }

    ll res = 0;
    for (int i = 0; i < n; ++i) {
        if (a[i] < b[i]) {
            res += a[i];
            if (a[i+1] <= b[i] - a[i]) {
                res += a[i+1];
                a[i+1] = 0;
            } else {
                res += b[i] - a[i];
                a[i+1] -= b[i] - a[i];
            }
        } else {
            res += b[i];
        }
    }
    cout << res << endl;
}