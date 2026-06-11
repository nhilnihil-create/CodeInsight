#include <bits/stdc++.h>
#define DAU  ios::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define PLEC exit(0);
using namespace std;
int n, v[100005], st, dr, mid, res, k;
int main() {
    DAU
    cin >> n;
    k = n / 2;
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    sort(v + 1, v + n + 1);
    for (int i = 1; i <= 1e5; ++i)
        if (v[k] <= i && v[k+1] > i)
            ++res;
    cout << res;
    PLEC
}
