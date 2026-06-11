#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0;i < n;i++)
using ll = long long;

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> s(m), c(m);
    rep(i,m) {
        cin >> s[i] >> c[i];
        s[i]--;
    }
    vector<int> ans(n,-1);
    rep(i,m) {
        if(n != 1 && s[i] == 0 && c[i] == 0) {
            cout << -1 << endl;
            return 0;
        }
        if(ans[s[i]] == -1) ans[s[i]] = c[i];
        else if(ans[s[i]] != c[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    rep(i,n) {
        if(n != 1 && ans[0] == -1) ans[0] = 1;
        if(ans[i] == -1) ans[i] = 0;
        cout << ans[i];
    }
    cout << endl;
}