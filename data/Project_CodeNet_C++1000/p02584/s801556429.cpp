#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
int main()
{
    // freopen("input01.txt", "r", stdin);
    // freopen("output01.txt", "w", stdout);
    ll int x, k, d;
    cin >> x >> k >> d;
    x=abs(x);
    ll int steps=min(k,x/d);
    x-=steps*d;
    k-=steps;
    if(k%2)
        cout<<(ll int)abs(d-x);
    else
    {
        cout<<(ll int)abs(x);
    }
    return 0;
}