#include <bits/stdc++.h>
using namespace std;
#define all(a) a.begin(), a.end()
#define rep(i, n) for(int i = 0; i < n; i++)
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    int n, cnt = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        if(i % 2 == 1)
            cnt++;
    }
    double ans = (double) cnt / n;
    cout << ans << "\n";
    return 0;
}
