#include<bits/stdc++.h>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <stdio.h>
#include <algorithm>
#include <map>
#include <queue>
#include <unordered_map>
#define ll long long
#define pii pair <int, int>
#define pll pair <long long, long long>
#define plxy pair <long long, pll>
#define INT_MAX 1e18
#define Keep_calm_You_are_still_learning ios_base::sync_with_stdio(false);cin.tie(NULL);
using namespace std;
using namespace std;
const int mod=1e9+7;
const int N=1e5+5;
ll fact[1000006],inv[1000006];
ll fp(ll base,ll exp)
{
    if (exp == 0)
        return 1;
    ll ans = fp(base, exp / 2);
    ans = (ans * ans) % mod;
    if (exp % 2 != 0)
        ans = (ans * (base % mod)) % mod;
    return ans;
}
void calcFacAndInv(ll n)
{
    fact[0] = inv[0] = 1;
    for (ll i = 1; i <= n; i++)
    {
        fact[i] = (i * fact[i - 1]) % mod;
        inv[i] = fp(fact[i], mod - 2);
    }
}
ll ncr(ll n, ll r)
{
    return ((fact[n] * inv[r]) % mod * inv[n - r]) % mod;
}

ll npr(ll n, ll r)
{
    return (fact[n] * inv[n - r]) % mod;
}
ll n,k;
int main()
{
    Keep_calm_You_are_still_learning
    calcFacAndInv(1e5);
    cin>>n>>k;
    for(ll i=k;i>=1;i--)
    {
        if(n-k+1>=k-i+1)
        {
            cout<<(((ncr(n-k+1,k-i+1))%mod)*((ncr(k-1,i-1))%mod))%mod<<endl;
        }
        else
        {
            cout<<0<<endl;
        }
    }
    return 0;
}
