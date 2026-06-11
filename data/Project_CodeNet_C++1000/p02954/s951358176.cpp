#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
/////////////////////////////////
int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<pair<char, int>> v(n);
    int cntL = 0, cntR = 0;
    rep(i, n)
    {
        if (s[i] == 'L')
        {
            cntL++;
            v[i] = make_pair('L', cntL);
        }
        else
            cntL = 0;
    }
    for (int i = n - 1; i >= 0; i--)
    {
        if (s[i] == 'R')
        {
            cntR++;
            v[i] = make_pair('R', cntR);
        }
        else
            cntR = 0;
    }
    vector<int> ans(n, 0);
    rep(i, n)
    {
        if (v[i].first == 'R')
        {
            if (v[i].second % 2 == 0)
            {
                ans[i + v[i].second]++;
            }
            else
            {
                ans[i + v[i].second - 1]++;
            }
        }

        else
        {
            if (v[i].second % 2 == 0)
            {
                ans[i - v[i].second]++;
            }
            else
            {
                ans[i - v[i].second + 1]++;
            }
        }
    }
    rep(i, n)
    {
        cout << ans[i];
        if (i != n - 1)
            cout << " ";
        else
            cout << endl;
    }
}