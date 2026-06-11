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

int main()
{
    string s;
    cin >> s;
    ll k;
    cin >> k;
    ll cnt = 1;
    vector<ll> a;
    for (ll i = 1; i < s.size(); i++)
    {
        // cnt++;
        // cout << s.at(i-1) << " " << s.at(i) << endl;
        if (s.at(i - 1) != s.at(i))
        {
            a.push_back(cnt);
            cnt = 1;
        }
        else
        {
            cnt++;
        }
    }
    a.push_back(cnt);

    ll ans = 0;
    if (a.size() == 1)
    {
        cout << k*s.size()/2 << endl;
        return 0;
    }

    // for(ll i = 0;i < a.size();i++)
    // {
    //     cout << a[i] << " ";
    // }
    // cout << endl;

    bool flag = false;
    int sub = 0;
    if(s.at(0) == s.at(s.size()-1) && (a[0]+a[a.size()-1])%2==0)
    {
        a[0] += a[a.size()-1];
        a[a.size()-1] = 0;
        flag = true;
    }
    for (ll i = 0; i < a.size(); i++)
    {
        ans += a[i] / 2;
    }
    if(flag)
    {
        sub--;
    }
    cout << ans * k + sub << endl;
}
