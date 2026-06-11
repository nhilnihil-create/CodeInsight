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

ll mypow(ll a, ll b)
{
    if (b == 1)
    {
        return a;
    }
    else
    {
        return a * mypow(a, b - 1);
    }
}

signed main()
{
    string s;
    cin >> s;
    int num_of_l = 0;
    int num_of_r = 0;
    int a = 0;
    rep(i, s.size())
    {
        //        cout << "i:" << i << endl;
        num_of_l = 0;
        num_of_r = 0;
        if (s[i] == 'R')
        {
            a = i;
            rep(j, s.size() - i)
            {
                if (s[a + j] == 'R')
                {
                    if (num_of_l == 0)
                    {
                        num_of_r++;
                    }
                    else
                    {
                        break;
                    }
                }
                else
                {
                    num_of_l++;
                }
            }
            //            cout << num_of_r << " " << num_of_l << endl;
            rep(j, num_of_r - 1)
            {
                cout << 0 << " ";
            }
            cout << (num_of_r + 1) / 2 + (num_of_l / 2) << " ";
            cout << num_of_r / 2 + (num_of_l + 1) / 2 << " ";
            rep(j, num_of_l - 1)
            {
                cout << 0 << " ";
            }
            i += num_of_l + num_of_r - 1;
        }
    }
    cout << endl;
    return 0;
}