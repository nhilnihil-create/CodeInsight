#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
    int a, b, m; cin >> a >> b >> m;
    vector<int> a_s(a);
    vector<int> b_s(b);
    vector<int> x(m), y(m), c(m);
    rep(i, a) cin >> a_s[i];
    rep(i, b) cin >> b_s[i];
    rep(i, m) cin >> x[i] >> y[i] >> c[i];
    int ans =  *min_element(a_s.begin(), a_s.end()) + *min_element(b_s.begin(), b_s.end());

    rep(i, m) {
        ans = min(ans, a_s[x[i]-1]+b_s[y[i]-1] - c[i]);
    }
    cout << ans << endl;
}