//#pragma GCC optimize ("O3")
//#pragma GCC target ("sse4")

#include <bits/stdc++.h>

using namespace std;

// CHECK THE LIMITS
typedef long long ll;

static const int NMAX = 1e5;

int gcd(int a, int b) {
  return b ? gcd(b, a%b) : a;
} 

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,k;
    cin >> n >> k;
    vector<int> v(n+1);
    ll sum =0;
    for(int i =0; i < n; ++i)
    {
        cin >> v[i];
        sum+=v[i];
    }
    vector<ll> fact;
    for(int i =1; i*i <=sum; ++i)
    {
        if(sum % i == 0)
        {
            fact.push_back(i);
            fact.push_back(sum/i);
        }
    }

    ll ans =1;
    for(int i =0; i < (int) fact.size(); ++i)
    {
        multiset<ll> vals;
        ll totalCost = 0;
        ll used = 0;

        for(int j = 0; j < n; ++j)
        {
            vals.insert(v[j] % fact[i]);
            totalCost += fact[i] - (v[j] % fact[i]);
        }

        for(auto it = vals.begin(); it != vals.end(); ++it)
        {
            used += *it;
            totalCost -= fact[i] - *it;
            if(used == totalCost && used <= k)
            {
                ans = max(ans, fact[i]);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}