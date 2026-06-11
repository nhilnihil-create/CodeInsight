#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1001001001;

int main() {
    int d;
    cin >> d;
    vector<int> c(26);
    rep(i, 26) {
        cin >> c[i];
    }
    
    vector<vector<int>> s(370, vector<int>(30));
    rep(i, d) {
        rep(j, 26) {
            cin >> s[i][j]; 
        }
    }
    vector<int> t(d);
    rep(i, d) {
        cin >> t[i];
    }
    
    ll ans = 0;
    vector<int> cnt(26, 1);
    rep(i, d) {
        ans += s[i][t[i]-1];
        rep(j, 26) {
            if (t[i]-1 == j) continue; 
            ans-= cnt[j] * c[j];
        }
        rep(l, 26) cnt[l]++;
        cnt[t[i]-1] = 1;
        cout << ans << endl;
    }


    return 0;
}