#include <bits/stdc++.h>
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define ALL(x) x.begin(),x.end()
using namespace std;


int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> d(n);
    rep (i, n) cin >> d[i];
    int ans=0;
    for (int i=0; i<n; ++i) {
        for (int j=i+1;j<n;++j) {
            ans += d[i]*d[j];
        }
    }
    cout << ans << endl;
    return 0;
}