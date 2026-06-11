#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n ; i++) {
        cin >> a[i];
    }
    int ans = 0;
    int x = 1;
    for (int i = 1; i <= n; i++) {
        if (a[i] != x) {
            ans++;
        }
        else {
            x++;
        }

    }
    if (x == 1) ans = -1;
    cout << ans << endl;
    return 0;
}