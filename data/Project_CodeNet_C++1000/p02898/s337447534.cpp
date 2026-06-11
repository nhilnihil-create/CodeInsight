#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main()
{
    ll n, k, ans = 0;
    cin >> n >> k;
    rep(i, n)
    {
        ll h;
        cin >> h;
        if (h >= k)
            ans++;
    }
    cout<<ans<<endl;
    return 0;
}