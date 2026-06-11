#include <bits/stdc++.h>
#include <iostream>
#include <ctime>
using namespace std;
#define _LL long long
#define rep(i, n) for (_LL i = 0; i < (_LL)(n); i++)
#define vecrep(itr, v) for (auto itr = (v).begin(); itr != (v).end(); itr++)

int main()
{
    string s, t; cin >> s >> t;
    vector<_LL> index[26];
    _LL slen = s.length();
    _LL tlen = t.length();
    rep(i, slen)
    {
        index[s[i] - 'a'].push_back(i);
    }

    _LL loop = 0;
    _LL i = -1;
    rep(j, tlen)
    {
        int nextc = t[j] - 'a';
        if( index[nextc].size() == 0 )
        {
            cout << -1 << endl;
            return 0;
        }
        auto itr = upper_bound(index[nextc].begin(), index[nextc].end(), i);
        if( itr == index[nextc].end() )
        {
            loop++;
            i = index[nextc][0];
        }
        else
        {
            i = *itr;
        }
    }

    cout << loop * slen + i + 1 << endl;

    return 0;    
}