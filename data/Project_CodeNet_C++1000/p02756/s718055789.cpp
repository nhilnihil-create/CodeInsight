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
    int q;
    cin >> s >> q;
    deque<string> ds;
    ds.push_back(s);
    bool is_reversed = false;
    rep(i, q)
    {
        int a;
        cin >> a;
        if (a == 1)
        {
            is_reversed = !is_reversed;
        }
        else
        {
            int f;
            string c;
            cin >> f >> c;
            if (f == 1)
            {
                if (!is_reversed)
                {
                    ds.push_front(c);
                }
                else
                {
                    ds.push_back(c);
                }
            }
            else
            {
                if (is_reversed)
                {
                    ds.push_front(c);
                }
                else
                {
                    ds.push_back(c);
                }
            }
        }
    }
    if (!is_reversed)
    {
        for (auto &i : ds)
        {
            cout << i;
        }
        cout << endl;
    }
    else
    {
        for (auto i = ds.rbegin(); i != ds.rend(); i++)
        {
            string s = *i;
            reverse(all(s));
            cout
                << s;
        }
        cout << endl;
    }

    return 0;
}