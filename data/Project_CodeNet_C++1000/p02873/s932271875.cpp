#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P;

int a[500000];

int main() {
    string s;
    cin >> s;
    int n = s.size();
    rep(i,n) {
        if (s[i] == '<') {
            a[i+1] = max(a[i+1], a[i]+1);
        }
    }
    for (int i = n-1; i >= 0; i--) {
        if (s[i] == '>') {
            a[i] = max(a[i], a[i+1]+1);
        }
    }
    Int ans = 0;
    for (int i = 0; i <= n; i++) {
        ans += a[i];
    }
    cout << ans << endl;
}