#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<ll> divisors(ll n) 
{
    vector<ll> res;
    for (ll i = 1; i <= n / i; ++i) 
    {
        if (n % i == 0)
        {
            res.push_back(i);
            
            if (n / i != i) 
                res.push_back(n / i);
        }
    }
    sort(res.begin(), res.end());
    return res;
}

int main()
{
    ll n, res;
    cin >> n;

    auto divs = divisors(n);
    ll mid = divs.size() / 2;

    if(divs.size() % 2 == 0)
        res = divs[mid - 1] + divs[mid] - 2;
    else 
        res = divs[mid] + divs[mid] - 2;

    cout << res << "\n";
    return 0;
}
