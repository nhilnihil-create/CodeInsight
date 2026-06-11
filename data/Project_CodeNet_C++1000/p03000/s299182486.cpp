#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define rep(i, n) for (int i = 0; i < n; ++i)

int main() {
    int n, x, tmp = 0, cnt = 0;
    int l[120];
    cin >> n >> x;
    rep(i, n) {
        cin >> l[i];
        tmp += l[i];
        if (tmp <= x) {
            cnt++;
        }
    }
    cout << cnt + 1 << endl;
    return 0;
}