#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

//最大公約数
ll gcd(ll m, ll n)
{
    if (m < n)
    {
        ll tmp = m;
        m = n;
        n = tmp;
    }

    while (1)
    {
        ll mod = m % n;
        if (mod == 0)
            return n;
        m = n;
        n = mod;
    }
}

//最小公倍数
ll lcm(ll m, ll n)
{
    return m * n / gcd(m, n);
}

int main()
{
    ll a,b;
    cin>>a>>b;
    cout<<lcm(a,b)<<endl;
    return 0;
}
