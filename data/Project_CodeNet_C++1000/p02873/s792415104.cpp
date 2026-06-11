#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <cmath>
#include <functional>

#define big ((long long)(1e9) + 7)

using namespace std;

typedef unsigned long long ull;
typedef long long ll;

#define DBG(x) cerr << #x << ": " << (x) << " (L" << __LINE__ << ")" << endl;

ll max_ll(ll a, ll b)
{
    if (a < b)
    {
        a = b;
    }
    return a;
}

int main()
{
    string s;
    cin >> s;
    vector<ll> a;
    ll nl = 0;
    ll nr = 0;
    if (s.at(0) == '<')
    {
        nl++;
        for(ll i = 1;i < s.size();i++)
        {
            if(s.at(i-1) != s.at(i) && nl != 0 && nr != 0)
            {
                a.push_back(max_ll(nl,nr));
                if(nl >= nr && nr >= 2)
                {
                    a.push_back(nr-1);
                }
                else if(nl <= nr && nl >= 2)
                {
                    a.push_back(nl-1);
                }
                nl = 0;
                nr = 0;
            }
            if(s.at(i) == '<') nl++;
            else nr++;
        }
    }
    else
    {
        bool flag = true;
        nr++;
        for(ll i = 1;i < s.size();i++)
        {
            if(flag && s.at(i-1) != s.at(i))
            {
                a.push_back(max_ll(nl,nr));
                nl = 0;
                nr = 0;
                flag = false;
            }
            if(s.at(i-1) != s.at(i) && nl != 0 && nr != 0)
            {
                a.push_back(max_ll(nl,nr));
                if(nl >= nr && nr >= 2)
                {
                    a.push_back(nr-1);
                }
                else if(nl <= nr && nl >= 2)
                {
                    a.push_back(nl-1);
                }
                nl = 0;
                nr = 0;
            }
            if(s.at(i) == '<') nl++;
            else nr++;
        }
    }
    a.push_back(max_ll(nl,nr));
    ll ans = 0;
    for(ll i = 0;i < a.size();i++)
    {
        ans += a[i]*(a[i]+1)/2;
    }
    cout << ans << endl;
}
