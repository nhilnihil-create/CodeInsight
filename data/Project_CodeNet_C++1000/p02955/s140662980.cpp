#include <iostream>
#include <cstdio>
#include <algorithm>

using namespace std;

typedef long long ll;

ll n, k;
ll a[505];
ll b[505];
ll sum, ans;

void f(ll p)
{
    ll t = 0;
    ll t2 = 0;
    for(ll i = 0; i < n; i++)
    {
        t += a[i] % p;
        b[i] = a[i] % p;
    }
    sort(b, b + n);
    for(ll i = 0; i < n - t / p; i++)
    {
        t2 += b[i];
    }
    if(t2 <= k) ans = max(ans, p);
}

int main()
{
    cin>>n>>k;
    for(ll i = 0; i < n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    for(ll i = 1; i * i <= sum; i++)
    {
        if(sum % i == 0) f(i), f(sum / i);
    }
    cout<<ans<<endl;
    return 0;
}
