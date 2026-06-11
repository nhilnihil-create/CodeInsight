#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll x,k,d;
    cin>>x>>k>>d;
    if (x == 0) {
        if (k%2) cout << d << '\n';
        else cout << 0 << '\n';
        return 0;
    }
    x = abs(x);
    ll a = x % d;
    ll b = x / d;
    if (b >= k) cout << x - d*k << '\n';
    else {
        ll c = k - b;
        if (c % 2) {
            cout << d - a << '\n';
        }
        else cout << a << '\n';
    }
    return 0;
    
}