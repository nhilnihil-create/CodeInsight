#include <bits/stdc++.h>

using namespace std;

#include <vector>
#include <map>
#include <set>
#include <queue>
#include <math.h>
#include <iostream>
#include <stdio.h>

typedef long long ll;
typedef vector<ll> vll;
typedef pair<ll,ll> pairll;

#define sll(x) scanf("%lld",&x);
#define READ freopen("in.txt","r",stdin)
#define WRITE freopen("out.txt","w",stdout)

#define ff first
#define ss second

inline ll ADD(ll a, ll b, ll mod)
{
    return (a + b + mod + mod)%mod;
}

inline ll SUBS(ll a, ll b, ll mod)
{
    return (a-b+mod + mod) %mod;
}

inline ll MUL(ll a, ll b, ll mod)
{
    return (a*b + mod)%mod;
}

ll bigMod(ll base, ll power, ll mod)
{
    if(!power) return 1;
    if(!base) return 0;

    ll temp = bigMod(base, power/2, mod);

    if(power%2 == 0)
    {
        return (temp*temp)%mod;
    }
    else return (((temp*temp)%mod)*base)%mod;
}

inline ll modInverse(ll a, ll modp)
{
    return bigMod(a, modp -2, modp);
}

inline ll modInverseExtended(ll a, ll m) 
{ 
    ll m0 = m; 
    ll y = 0, x = 1; 
  
    if (m == 1) 
      return 0; 
  
    while (a > 1) 
    { 
        // q is quotient 
        ll q = a / m; 
        ll t = m; 
  
        // m is remainder now, process same as 
        // Euclid's algo 
        m = a % m, a = t; 
        t = y; 
  
        // Update y and x 
        y = x - q * y; 
        x = t; 
    } 
  
    // Make x positive 
    if (x < 0) 
       x += m0; 
  
    return x; 
} 
  
int getOdd(int n, int r)
{
    // if(n == r) return 1;
    // else if(n % 2 == 0 && r%2==1) return 0;
    // return getOdd(n/2,r/2);

    if(r & n-r) return 0;
    return 1;
}

void autoinput()
{
    READ; 
    //WRITE;
}

int main()
{
    //autoinput();

    ll n; cin >> n;

    ll arr[n+1];
    ll arra[n+1];

    bool one = false;
    for(ll i = 0; i < n; i++)
    {
        int in;
        scanf("%1d",&in);
        arr[i] = in - 1;
        if(in == 2){
            if(!one) memset(arra, 0, sizeof arra);
            one = true;
            arra[i] = 1;
        }
        else if(!one)
        {
            arra[i] = arr[i]/2;
        }
    }

    ll cur = 0;

    for(ll i = 0; i < n; i++)
    {
        //cout << getOdd(n-1,i);
        //cout << arra[i];
        cur ^= arra[i] * getOdd(n-1,i);
    }
    if(!one) cur *= 2;
    
    cout << cur << endl;
}

