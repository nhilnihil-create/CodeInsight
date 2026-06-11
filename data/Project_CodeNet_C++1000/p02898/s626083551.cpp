#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> h(n);
    int ans = 0;
    rep(i, n)
    {
        cin >> h[i];
        if (k <= h[i])
            ans++;
    }
    cout << ans << endl;
    return 0;
}