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

signed main()
{
    string s;
    int k;
    cin >> s >> k;
    ll cnt = 0;
    ll cnt2 = 0;
    ll cnt3 = 0;
    string s1 = s;
    string s2 = s + s;
    string s3 = s + s + s;
    rep(i, s1.size() - 1)
    {
        if (s1[i] == s1[i + 1])
        {
            s1[i + 1] = 0;
            cnt++;
        }
    }
    rep(i, s2.size() - 1)
    {
        if (s2[i] == s2[i + 1])
        {
            s2[i + 1] = 0;
            cnt2++;
        }
    }
    rep(i, s3.size() - 1)
    {
        if (s3[i] == s3[i + 1])
        {
            s3[i + 1] = 0;
            cnt3++;
        }
    }
    if (k == 1)
    {
        cout << cnt << endl;
    }
    else if (k % 2 == 1)
    {
        cout << cnt + (cnt3 - cnt) * (k / 2) << endl;
    }
    else
    {
        cout << cnt + (cnt3 - cnt) * (k / 2 - 1) + (cnt2 - cnt) << endl;
    }
    //    cout << cnt + (cnt2 - cnt) * (k - 1) << endl;

    return 0;
}