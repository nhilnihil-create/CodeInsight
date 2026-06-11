#include <bits/stdc++.h>
using namespace std;
using ll = long long;


ll gcd(ll a, ll b)
{
    if(a % b == 0)
        return b;
    return gcd(b, a % b);
}

int main()
{
    ll a, b;
    cin >> a >> b;

    ll res = (a * b) / gcd(a, b); 
    cout << res << "\n";
    return 0;
}