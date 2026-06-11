#include <bits/stdc++.h>
 
using namespace std;
 
const long long mod = 1e9 + 7ll ;
const int MAX = 5000 ;

long long modpower(long long a , long long b)
{
    if(b == 0)
        return 1ll ;
    long long x = modpower(a , b / 2ll) ;
    x = (x * x) % mod ;
    if(b & 1)
        return (x * a) % mod ;
    return (x % mod) ;
}
 
struct combination
{
    vector<long long>fact , inv ;
    combination(int sz) : fact(sz + 1) , inv(sz + 1)
    {
        fact[0] = 1ll ;
        inv[0] = 1ll ;
        for(long long i = 1 ; i <= sz ; ++i)
            fact[i] = (fact[i-1] * i) % mod ;
        inv[sz] = modpower(fact[sz] , mod - 2ll) ;
		for(long long i = sz-1; i >= 1; --i)
		    inv[i] = (inv[i+1] * (i+1)) % mod;
    }
    long long choose(int n , int k) const
    {
        if(k < 0 || n < k)
            return 0 ;
        return ((((fact[n] * inv[k]) % mod) * inv[n - k]) % mod) ;
    }
};

int n , k ;
combination comb(MAX) ;

int main()
{
	ios_base::sync_with_stdio(0) ;
	cin.tie(0) ;
	cin>>n>>k ;
    int g = n-k ;
    for(int i = 0 ; i <= k-1; ++i)
    {
        if(g < i)
        {
            cout<<0<<"\n" ;
            continue ;
        }
        long long x = comb.choose(k-1 , i) % mod ;
        long long y = comb.choose(i+2+g-i-1 , g-i) % mod ;
        x = (x * y) % mod ;
        cout<<x<<"\n" ;
    }
    return 0 ;
}		
