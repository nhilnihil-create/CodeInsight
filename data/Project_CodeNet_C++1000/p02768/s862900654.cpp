#include <bits/stdc++.h>

using namespace std;

const int N = 10000 + 4, mod = 1e9+7;

long long n  , a , b  ;

long long fpow(long long a , long long b )
{
    if(!b)
        return 1;
    long long ret = fpow(a , b/2);
    ret = (ret*ret)%mod;
    if(b%2)
        ret = (ret*a)%mod;
    return ret ;
}

long long binomialCoeff(int n, int k)
{
    long long res = 1;
    if ( k > n - k )
        k = n - k;
    for (int i = 0; i < k; ++i)
    {
        res = (res  * (n - i) )%mod;
        res = (res *  fpow(i + 1 , mod-2 ))%mod;
    }
    return res;
}

int main()
{
    cin>>n>>a>>b;
    long long sol = (fpow(2 , n) - binomialCoeff(n , a) - binomialCoeff(n ,  b) - 1);
    sol = (sol%mod + mod)%mod;
    cout<<sol;
    return 0;
}

