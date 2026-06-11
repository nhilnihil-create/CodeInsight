#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;
const ll INF = 10010010010010010;

int main() {
    int n; cin >> n;
    long double a[n]; rep(i,n) cin >> a[i];
    long double ans = 0;
    rep(i,n) {
        ans += 1 / a[i];
    }
    cout << setprecision(15) << 1 / ans << endl;
    return 0;
}
