#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a;
    double ans = 0.0;
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a;
        ans += 1.0 / a;
    }
    ans = 1.0 / ans;
    cout << ans;

    return 0;
}
