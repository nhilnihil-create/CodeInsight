#include <bits/stdc++.h>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <utility>

typedef long long ll;
typedef unsigned long long ull;

#define vi std::vector<int>
#define vl std::vector<ll>
#define floop(n) for(int i = 0; i < n; ++i)
#define print(x) std::cout << x << std::endl;

const ll INF = 1e18;
const ll MOD = 1e9+7;

ll gcd(ll a, ll b) { return a == 0 ? b : gcd(b%a, a); }
ll mod(ll a) { return a % MOD < 0 ? (a % MOD) + MOD : a % MOD; }
ll mod_add(ll a, ll b) { return (a%MOD + b%MOD) % MOD; }
ll mod_sub(ll a, ll b) { return mod((a%MOD - b%MOD) % MOD); }
ll mod_mul(ll a, ll b) { return (a%MOD * b%MOD) % MOD; }
ll mod_pow(ll a, ll b) 
{
    if(b == 0) return 1;
    ll p = mod_pow(a, b/2) % MOD;
    p = mod_mul(p, p);
    return (b%2 == 0) ? p : mod_mul(a, p);
}
ll mod_inv(ll a) { return mod_pow(a, MOD-2); }
ll mod_div(ll a, ll b) { return a%MOD * mod_inv(b) % MOD; }

ll res(ll n)
{
    ll ten = 1, nine = 1, eight = 1;
    while(n > 0)
    {
        ten = mod_mul(ten, 10);
        nine = mod_mul(nine, 9);
        eight = mod_mul(eight, 8);
        n--;
    }
    
    return mod_add(mod_sub(mod_sub(ten, nine), nine), eight);
}

int main()
{
    ll N;
    std::cin >> N;

    if(N == 1)
    {
        print(0);
    }

    else
    {
        print(res(N));
    }
    return 0;
}