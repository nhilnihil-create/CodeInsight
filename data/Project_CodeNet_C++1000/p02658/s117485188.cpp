#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<math.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
    ll n;
    cin >> n;
    vector<ll> a(n);
    rep(i, n) cin >> a[i];
    ll p, q;
    p = 1;
    rep(i, n) p *= a[i];

    ll count = 0;
    rep(i, n)
    {
        if (a[i] == 0) count++;
    }
    if (count != 0)
    {
        cout << '0' << "\n";
    }
    else
    {
        q = p;
        rep(i, n) q /= a[i];
        if (q == 1 && p <= 1000000000000000000)
        {
            cout << p << "\n";
        }
        else cout << "-1" << "\n";
    }

    return 0;
}