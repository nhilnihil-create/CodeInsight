#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = int64_t;
using pint = pair<int, int>;

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int sum = 0;
    rep(i, n) sum += a[i];
    int ans = 0;
    rep(i, n) if (a[i] * 4 * m >= sum)++ ans;
    if (ans < m)
        cout << "No" << endl;
    else
        cout << "Yes" << endl;
}