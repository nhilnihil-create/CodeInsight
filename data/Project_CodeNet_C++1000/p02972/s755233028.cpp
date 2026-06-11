#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    rep(i,n) cin >> a[i+1];
    vector<int> b(n+1);
    for (int i = n; i >= 1; i--) {
        int sum = 0;
        for (int j = i+i; j <= n; j += i) {
            sum ^= b[j];
        }
        b[i] = a[i]^sum;
    }
    vector<int> ans;
    rep(i,n) {
        if (b[i+1]) ans.push_back(i+1);
    }
    cout << ans.size() << endl;
    rep(i,ans.size()) cout << ans[i] << endl;
    return 0;
}