#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int m = 0;
    int ans = 0;
    rep(i,3) {
        int t;
        cin >> t;
        ans += t;
        m = max(m,t);
    }
    cout << ans-m << endl;
    return 0;
}
