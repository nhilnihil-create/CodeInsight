#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n; cin >> n;
    vector<long double> a(n); rep(i,n) cin >> a[i];
    sort(a.begin(), a.end());
    long double ans = (a[0] + a[1]) / 2;
    //cout << ans << endl;
    rep(i,n-2) {
        ans = (ans + a[i+2]) / 2;
    }
    cout << ans << endl;
    return 0;
}
