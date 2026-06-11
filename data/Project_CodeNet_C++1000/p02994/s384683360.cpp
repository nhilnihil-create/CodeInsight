#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, l;
    cin >> n >> l;
    vector<int> t(n);
    int sum = 0;
    rep(i, n)
    {
        t[i] = l + i;
        sum += t[i];
    }
    int mn = 1e9;
    int ans = 0;
    rep(i, n)
    {
        int r = sum - t[i];
        if (mn > abs(sum - r))
        {
            mn = abs(sum - r);
            ans = r;
        }
    }
    cout << ans << endl;
    return 0;
}