#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int st[200002], dr[200002], v[200002], n;
int main() {
    DAU
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    for (int i = 1; i <= n; ++i)
        st[i] = max(v[i-1], st[i-1]);
    for (int i = n; i >= 1; --i)
        dr[i] = max(v[i+1], dr[i+1]);
    for (int i = 1; i <= n; ++i)
        cout << max(st[i], dr[i]) << '\n';
    PLEC
}
