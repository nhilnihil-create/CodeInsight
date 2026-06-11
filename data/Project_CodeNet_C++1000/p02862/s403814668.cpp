#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> ii;
typedef vector<ii> vii;

const ll MOD =1000000007; 


ll bpow(ll x, ll y)
{
    ll res=1;
    x = x % MOD;
    while(y>0)
    {
        if(y&1)
        {
            res = (res*x) % MOD;
        }
        y>>=1;
        x = (x *x) % MOD;
    }
    return res;
}


ll inverse(ll a)
{
    return bpow(a, MOD -2);
}

ll nCk(ll n, ll k, vector<ll> & fact)
{
    if (n<k || k<0) return 0;

    return (( (fact[n] * inverse(fact[k]) % MOD )  * inverse(fact[n-k]) ) % MOD ) % MOD;
    
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    

    ll x,y;
    cin>>x>>y;

    if((x+y) % 3 != 0 )
    {
        cout<<0<<endl;
        return 0;
    } 
    ll n = (x +y)/3;
    vector<ll> fact(n+1);
    fact[0]=fact[1]=1;
    for(ll i=2;i<=n;++i)
        fact[i] = (fact[i-1] *i)  % MOD;

    cout<<nCk(n,(2*y -x)/3, fact)<<endl;

    return 0;
}