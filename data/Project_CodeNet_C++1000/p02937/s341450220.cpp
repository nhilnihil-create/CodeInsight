#include <bits//stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ALL(obj) begin(obj), end(obj)
typedef long long int ll;
int main(void) {
    string s, t; cin >> s >> t; ll ans = 0,now = -1;
    vector<vector<int>> al(26);
    int n = s.size();
    rep(i, s.size()*2) al[s[i%n] - 'a'].push_back(i);
    rep(i, t.size()) {
        if (al[t[i] - 'a'].size() == 0) {
            cout << -1 << endl;
            return 0;
        }int ti = t[i] - 'a';
        auto it = upper_bound(ALL(al[ti]), now);// nowより大きい値
        ans += *it - now; now = *it % n;
    }cout << ans << endl;
}