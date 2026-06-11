#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, k;
    cin >> n >> k;
    int ans = 0;
    while(n > 0) {
        n /= k;
        ans++;
    }
    cout << ans << "\n";
    return 0;
}
