#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> k >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    sort(a.begin(), a.end());
    int dis = 0;
    rep(i, n)
    {
        if (i < n - 1)
            dis = max(dis, abs(a[i] - a[i + 1]));
        else
            dis = max(dis, abs(a[0] + k - a[i]));
    }
    cout << k - dis << endl;
    return 0;
}