//ranger2k aka Rishabh Agarwal

#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <functional>
using namespace __gnu_pbds;

#define ordered_set tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update>
#define F first
#define S second
#define ll long long int

const ll mod = INT64_MAX;
const ll INF = 1e18;
const long double PI = 3.1415926;

ll power(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll temp = power(a, b / 2) % mod;
    if (b % 2 == 0)
    {
        return (temp * temp) % mod;
    }
    else
    {
        return ((a * temp) % mod * temp) % mod;
    }
}

ll gcd(ll a, ll b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

#ifndef ONLINE_JUDGE
    freopen("inp.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif

    ll No_of_cases;
    No_of_cases = 1;
    //cin >> No_of_cases;
    // ll Case = 1;
    while (No_of_cases--)
    {
        // ll ans = 0;
        ll n, k;
        cin >> n >> k;
        ll a[n];
        for (ll x = 0; x < n; x++)
        {
            cin >> a[x];
        }
        unordered_set<ll> s;
        ll count = 0;
        ll temp = 0;
        while (true)
        {
            if (s.find(temp) == s.end())
            {
                s.insert(temp);
                temp = a[temp] - 1;
                count++;
            }
            else
            {
                break;
            }
        }
        ll temp2 = 0;
        ll count1 = 0;
        while (temp2 != temp)
        {
            count1++;
            temp2 = a[temp2] - 1;
        }
        if (k >= count1)
        {
            k = k - count1;
            k = k % (count - count1);
            while (k)
            {
                temp = a[temp] - 1;
                k--;
            }
            cout << temp + 1 << "\n";
        }
        else
        {
            temp = 0;
            while (k)
            {
                temp = a[temp] - 1;
                k--;
            }
            cout << temp + 1 << "\n";
        }
        // cout << "Case #" << Case << ": " << ans << "\n";
        // Case++;
    }
    return 0;
}
