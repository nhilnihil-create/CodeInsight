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
    int n, m;
    cin >> n >> m;
    vector<int> a(n+1, -1);
    int s, c;
    for (int i = 0; i < m; ++i) {
        cin >> s >> c;
        if (a[s] != -1 && a[s] != c) {
            cout << -1 << endl;
            return 0;
        }
        a[s] = c;
    }
    if (n > 1 && a[1] == 0) {
        cout << -1 << endl;
        return 0;
    }
    if (n == 1 && a[1] == -1) {
        cout << 0 << endl;
        return 0;
    }
    for (int i = 0; i < n; ++i) {
        if (i == 0 && a[i+1] == -1) a[i+1] = 1;
        else if (a[i+1] == -1) a[i+1] = 0;
    }
    for (int i = 0; i < n; ++i) {
        cout << a[i+1];
    }
    cout << endl;
}