#include <bits/stdc++.h>
#define ll long long
using namespace std;
ll n, l, r, k, ans = 1e9;
ll a[200009];
void inp()
{
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        r = max(r, a[i]);
    }
}
bool check(ll m)
{
    ll t = 0;
    for (int i = 1; i <= n; i++)
    {
        t += a[i]/m;
        if (a[i] % m == 0) t--;
        if (t > k) return false;
    }
    return (t <= k);
}
void process()
{
    sort(a+1, a+1+n);
    l = 1;
    while (l <= r)
    {
        ll m = (l+r)/2;
        if (check(m))
        {
            ans = min(ans, m);
            r = m-1;
        } else l = m+1;
    }
    cout << ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    //freopen("test.inp","r", stdin);
    inp();
    process();
    return 0;
}
