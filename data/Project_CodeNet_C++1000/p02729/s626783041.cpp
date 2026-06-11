#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, m, cnt = 0;
    cin >> n >> m;
    int ans = 0;
    ans += n * (n - 1) / 2;
    ans += m * (m - 1) / 2;
    cout << ans << "\n";
    return 0;
}
