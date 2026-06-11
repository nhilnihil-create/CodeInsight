#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    ll n,N;
    cin >> N;
    n = N;
    vector<pair<ll,ll>>v;
    for(ll num = 2; num <= sqrt(n); num++)
    {
        ll count = 0;
        if(n == 1) break;
        while(n % num == 0)
        {
            n = n / num;
            count++;
        }
        if(count != 0)
        {
            v.push_back(pair(num,count));
        }
    }
    if(n > 1) v.push_back(pair(n,1));
    ll ans = 0;
    for(ll i = 0; i < v.size(); i++)
    {
        for(ll j = 1; j <= v[i].second;j++)
        {
            if(N == 1) break;
            ll num = pow(v[i].first,j);
            if(N % num == 0)
            {
                N = N / num;
                ans++;
            }
        }
        if(N == 1) break;
    }
    cout << ans << endl;
}