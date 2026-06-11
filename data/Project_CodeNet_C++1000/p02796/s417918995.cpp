#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main (void)
{
    int n;
    cin >> n;
    vector<pair<ll,ll>> x(n);

    for (int i = 0;i < n;i++)
    {
        ll _x,_y;
        cin >> _x >> _y;
        x[i].first = _x-_y;
        x[i].second = _x+_y;
    }
    
    sort(x.begin(),x.end(),
         [](pair<ll,ll> a, pair<ll,ll> b)
         {
             if (a.second == b.second) return a.first < a.second;
             else return a.second < b.second;
         });

    int ans = 1;
    ll posi = x[0].second;
    for (int i = 1;i < n;i++)
    {
        if (posi > x[i].first) continue;
        posi = x[i].second;
        ans++;
    }

    cout << ans << endl;

    
    
    return 0;
}
