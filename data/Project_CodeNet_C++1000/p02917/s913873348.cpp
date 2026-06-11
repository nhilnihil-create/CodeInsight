#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;



int main() {
    int n;
    cin >> n;
    vector<int> b(n-1);
    rep(i,n-1) cin >> b[i];
    vector<int> a(n);
    rep(i,n) {
        if (i == 0) a[i] = b[i];
        else if (i == n-1) a[i] = b[i-1];
        else {
            if (b[i]-b[i-1] >= 0) a[i] = b[i-1];
            else a[i] = b[i];
        }
    }
    int ans = 0;
    rep(i,n) ans += a[i];
    cout << ans << endl;
    return 0;
}