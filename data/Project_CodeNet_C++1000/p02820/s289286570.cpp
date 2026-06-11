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
    int n, k;
    cin >> n >> k;
    ll ans = 0;
    int r, s, p;
    cin >> r >> s >> p;
    string str;
    cin >> str;
    rep(i, n)
    {
        if (i < k)
        {
            if (str[i] == 'r')
            {
                ans += p;
            }
            if (str[i] == 'p')
            {
                ans += s;
            }
            if (str[i] == 's')
            {
                ans += r;
            }
        }
        else {
            if(str[i]==str[i-k]){
                str[i] = 0;
            }
            else {
                if (str[i] == 'r')
                {
                    ans += p;
                }
                if (str[i] == 'p')
                {
                    ans += s;
                }
                if (str[i] == 's')
                {
                    ans += r;
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}