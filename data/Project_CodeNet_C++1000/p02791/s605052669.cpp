#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int INF = 1001001001;

int main() {
    int n;
    cin >> n;
    int m = INF;
    int ans = 0;
    rep(i,n) {
        int p;
        cin >> p;
        if (p <= m) ans++;
        m = min(p, m);
    }
    cout << ans << endl;
    return 0;
}