#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rng(i, a, b) for (int i = int(a); i < int(b); i++)
#define rep(i, b) rng(i, 0, b)
#define gnr(i, a, b) for (int i = int(b) - 1; i >= int(a); i--)
#define per(i, b) gnr(i, 0, b)
#define bg begin()
#define ed end()
#define all(x) x.bg, x.ed
#define vi vector<int>
template <class t, class u>
bool chmax(t &a, u b)
{
    if (a < b)
    {
        a = b;
        return true;
    }
    return false;
}
template <class t, class u>
bool chmin(t &a, u b)
{
    if (b < a)
    {
        a = b;
        return true;
    }
    return false;
}

ll mod = 1000000007;

signed main()
{
    int n;
    cin >> n;
    vi l;
    rep(i, n)
    {
        int a;
        cin >> a;
        l.push_back(a);
    }
    sort(all(l));
    ll ans = 0;
    rep(i, n)
    {
        for (int j = i + 1; j < n; j++)
        {
            //二辺が決まると条件が決まる
            //a-b<c,b-a<c,c<a+b
            int left = max(l[i] - l[j], l[j] - l[i]);
            int right = l[i] + l[j];
            //            auto it1=upper_bound(all(l),left);
            auto it = lower_bound(all(l), right);
            //            cout << i << " " << j << " " << it - l.begin() << endl;
            if (it - l.begin() - j - 1 > 0)
            {
                ans += it - l.begin() - j - 1;
            }
        }
    }
    cout << ans << endl;
    return 0;
}