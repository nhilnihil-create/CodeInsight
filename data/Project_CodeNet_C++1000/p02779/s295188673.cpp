#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;	

int main() {
    int n; cin >> n;
    vector<int> a(n);
    REP(i, n) cin >> a[i];
    sort(ALL(a));
    REP(i, n - 1) {
        if (a[i] == a[i + 1]) {
            cout << "NO" << endl;
            break;
        }
        if (i == n - 2) {
            cout << "YES" << endl;
        }
    }
}
