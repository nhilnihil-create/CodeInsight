#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    string s; cin >> s;
    _LL k; cin >> k;
    int l = s.length();
    bool pre = false;
    _LL count = 0;
    _LL c1 = 0;
    rep(i, l)
    {
        if(i == 0) continue;
        if( pre )
        {
            pre = false;
            continue;
        }
        if(s[i - 1] == s[i]) 
        {
            pre = true;
            count++;
        }
    }
    if( pre || s[l - 1] != s[0] || k == 1)
    {
        cout << count * k;
    }
    else
    {
        c1 = count;
        pre = true;
        count = 1;
        rep(i, l)
        {
            if(i == 0) continue;
            if( pre )
            {
                pre = false;
                continue;
            }
            if(s[i - 1] == s[i]) 
            {
                pre = true;
                count++;
            }
        }

        if( pre )
        {
            cout << (count + c1) * (k / 2) + c1 * (k % 2);
        }
        else
        {
            cout << c1 + (k - 1) * count;
        }       
    }
    return 0;
}