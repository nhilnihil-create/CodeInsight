#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
const int N(2e5 + 5);
int n, a[N], cnt, res;
bool bila[N];
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> a[i];
    for (int i = n; i >= 1; --i) {
        cnt = 0;
        for (int j = i + i; j <= n; j += i)
            cnt += bila[j];
        if ((cnt & 1) != (a[i] & 1))
            bila[i] = true, ++res;
    }
    cout << res << '\n';
    for (int i = 1; i <= n; ++i)
        if (bila[i])
            cout << i << '\n';
    PLEC
}
