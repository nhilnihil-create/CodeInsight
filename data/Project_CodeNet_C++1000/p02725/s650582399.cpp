#include <bits/stdc++.h>

using namespace std;

const int N = 2e6 + 5;

int a[N];

int n, k;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    cin >> k >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    a[n + 1] = a[1] + k;
    int res = N;
    for (int i = 1; i <= n; i++)
        res = min(res, k - (a[i + 1] - a[i]));
    cout << res << endl;
    return 0;
}
