#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <bits/stdc++.h>
#include <iomanip>
#include <numeric>
#include <utility>
#include <map>
#include <algorithm>
typedef long long ll;
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
#define MX 1000000000

int main(void)
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    ll n;
    cin >> n;
    map<string, int> mp;
    ll ans = 0;
    for (int i = 0; i < n; ++i)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        if (mp[s] == 0)
            mp[s] = 1;
        else
            ans += mp[s]++;
    }
    cout << ans << endl;
}
