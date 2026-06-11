#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int n;
    cin >> n;
    vector<int> w(n);
    rep(i,n) cin >> w[i];
    int ans = accumulate(w.begin(), w.end(), 0);
    rep(i,n) {
        int s1 = 0, s2 = 0;
        rep(j,i) s1 += w[j];
        for (int j = i; j < n; j++) s2 += w[j];
        ans = min(ans,abs(s1-s2));
    }
    cout << ans << endl;
    return 0;
}
