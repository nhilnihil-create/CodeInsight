#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, a[101];
    cin >> n;
    for(int i = 0; i < n; i++) {
        cin >> a[i];
    }
    int ans = 0;
    for(int i = 0; i < n; i++) {
        for(int j = i + 1; j < n; j++) {
            ans = ans + a[i] * a[j];
        }
    }
    cout << ans << "\n";
    return 0;
}
