#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; i++)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<pi, pi> pp;
typedef pair<ll, ll> pl;
const double EPS = 1e-9;
const ll MOD = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;

int n;

int main() {
    cin >> n;
    int m = 1;
    if (n <= 2) {
        cout << "No" << endl;
        return 0;
    }
    while (2*m-1 <= n) {
        m *= 2;
    }
    if (m == n) {
        cout << "No" << endl;
        return 0;
    }
    m--;
    cerr << m << endl;
    cout << "Yes" << endl;
    rep(i,m-1) cout << i+1 << " " << i+2 << endl;
    cout << m << " " << n+1 << endl;
    rep(i,m-1) cout << n+i+1 << " " << n+i+2 << endl;
    int pos = 1;
    for (int i = m+1; i <= n; i++) {
        if (i == m+1) {
            cout << i << " " << 1 << endl;
            cout << i+1 << " " << i << endl;
            cout << pos << " " << n+i+1 << endl;
            cout << n+i+1 << " " << n+i << endl;
            i++;
        } else {
            cout << i << " " << n+i-1 << endl;
            cout << pos << " " << n+i << endl;
        }
        pos++;
    }
}
