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
    int n, a, b, c, d;
    cin >> n >> a >> b >> c >> d;
    string s;
    cin >> s;
    if (c < d)
    {
        for (int i = b; i <= d - 2; i++)
        {
            if (s[i - 1] == '#' && s[i] == '#')
            {
                cout << "No" << endl;
                return 0;
            }
        }
        for (int i = a; i <= c - 2; i++)
        {
            if (s[i - 1] == '#' && s[i] == '#')
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    else
    {
        for (int i = b; i <= d - 2; i++)
        {
            if (s[i - 1] == '#' && s[i] == '#')
            {
                cout << "No" << endl;
                return 0;
            }
        }
        bool f = false;
        for (int i = b; i <= d; i++)
        {
            if (s[i - 2] == '.' && s[i - 1] == '.' && s[i] == '.')
            {
                f = true;
            }
        }
        if (!f)
        {
            cout << "No" << endl;
            return 0;
        }
        for (int i = a; i <= c - 2; i++)
        {
            if (s[i - 1] == '#' && s[i] == '#')
            {
                cout << "No" << endl;
                return 0;
            }
        }
    }
    cout << "Yes" << endl;
    return 0;
}