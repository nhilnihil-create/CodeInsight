/**
*    created: 12.05.2020 00:35:15
**/
#include <bits/stdc++.h>
#define int long long
const int INF = 1e18L + 5;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define rep2(i, s, n) for (int i = (s); i < (int)(n); i++)
using namespace std;

signed main() {

    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n; cin >> n;
    vector<int> p(n);
    rep(i,n) {
        cin >> p[i];
    }
    int cnt = 0;
    rep2(i,1,n-1) {
        if ((p[i-1] < p[i] && p[i] < p[i+1]) || (p[i+1] < p[i] && p[i] < p[i-1])) cnt++;
    }
    cout << cnt << endl;
    return 0;
}