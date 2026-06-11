#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll gcd(ll a, ll b)
{
    if(b == 0) return a;
    return gcd(b, a%b);
}
int main()
{
    int n, m;
    cin >> n >> m;
    set<ll> a;
    for(int i = 0; i < n; i++)
    {
        ll aa;
        cin >> aa;
        a.insert(aa);
    }
    int count = 0;
    ll tmp = *a.begin();
    while(tmp % 2 == 0)
    {
        tmp /= 2;
        count++;
    }
    for(ll tt : a)
    {
        int tc = 0;
        while(tt % 2 == 0)
        {
            tt /= 2;
            tc++;
        }
        if(tc != count)
        {
            cout << 0 << endl;
            return 0;
        }
    }
    ll lcm = 1;
    for(ll tt : a)
    {
        ll g = gcd(lcm, tt/2);
        lcm = lcm * tt/2 / g;
    }
    ll c = m / lcm;
    cout << (c+1)/2 << endl;
}

