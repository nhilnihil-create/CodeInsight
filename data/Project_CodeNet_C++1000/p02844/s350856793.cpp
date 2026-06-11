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

//ll mod = 1000000007;
ll mod = 998244353;

signed main()
{
    int n;
    cin >> n;
    string s;
    cin >> s;
    //ll ans = 0;
    vector<set<int>> vs1(n);
    vector<set<int>> vs2(n);
    rep(i, n - 1)
    {
        auto s1 = vs1[i];
        vs1[i + 1] = vs1[i];
        vs1[i + 1].insert(s[i]);
        auto s2 = vs2[n - 1 - i];
        vs2[n - 2 - i] = vs2[n - 1 - i];
        vs2[n - 2 - i].insert(s[n - 1 - i]);
    }
    set<int> pass;
    rep(i, n)
    {
        for (auto &j : vs1[i])
        {
            for (auto &k : vs2[i])
            {
                pass.insert((j - '0') * 100 + (s[i] - '0') * 10 + (k - '0'));
            }
        }
    }
    cout << pass.size() << endl;
    return 0;
}