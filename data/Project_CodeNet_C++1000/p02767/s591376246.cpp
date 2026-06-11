#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    rep(i, n) cin >> x[i];
    int ans = 1e9;
    rep(p, 101)
    {
        int sum = 0;
        rep(i, n)
        {
            int pp = x[i] - p;
            sum += pp * pp;
        }
        ans = min(ans, sum);
    }
    cout << ans << endl;
    return 0;
}