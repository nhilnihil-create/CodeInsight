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
    vi a;
    rep(i, n)
    {
        int b;
        cin >> b;
        a.push_back(b);
    }
    //all 0
    bool f = true;
    rep(i, n)
    {
        if (a[i] != 0)
        {
            f = false;
            break;
        }
    }
    if (f)
    {
        cout << "Yes" << endl;
        return 0;
    }
    //2/3 x, 1/3 0
    if (n % 3 != 0)
    {
        cout << "No" << endl;
        return 0;
    }
    map<int, int> m;
    rep(i, n)
    {
        m[a[i]]++;
    }
    if (m.size() == 2)
    {
        if (m[0] == n / 3)
        {
            cout << "Yes" << endl;
        }
        else
        {
            cout << "No" << endl;
        }
    }
    else if (m.size() == 3)
    {
        int res = 0;
        for (auto &i : m)
        {
            res = (res ^ i.first);
        }
        if (res != 0)
        {
            cout << "No" << endl;
            return 0;
        }

        for (auto &i : m)
        {
            if (i.second != n / 3)
            {
                cout << "No" << endl;
                return 0;
            }
        }
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}