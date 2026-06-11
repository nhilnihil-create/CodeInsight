#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll N = 1e6 + 10;
bool vis[N];
vector<ll> prime;
ll factor[20], cntp, a, b;

void get_prime()
{
    memset(vis,0, sizeof(vis));
    for(ll i = 2; i <= N; ++i){
        if(!vis[i]) prime.push_back(i);
    for(ll p : prime){
        if(i * p > N) break;
        vis[i * p] = true;
        if(i % p == 0) break;
    }
    }
}

ll gcd(ll a, ll b)
{
    return !b ? a : gcd(b, a % b);
}

void get_factor(ll n)
{
    memset(factor, 0, sizeof(factor));
    ll fac = 1;
    for(ll p : prime){
        fac = 1;
        if(n % p == 0){
            while(n % p == 0){
                n /= p;
                fac *= p;
            }
            ++cntp;
            factor[cntp] = fac;
        }
    }
    if(n > 1) factor[++cntp] = n;
}


int main()
{
    get_prime();
    cin >> a >> b;
    ll m = gcd(a, b);
    get_factor(m);
    cout << cntp + 1 <<  '\n';
    return 0;
}