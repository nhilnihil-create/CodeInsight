#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define M 1000000007
#define MOD 1000000007

long long mod(long long x){
        return ((x%M + M)%M);
    }
    long long add(long long a, long long b){
        return mod(mod(a)+mod(b));
    }
    long long mul(long long a, long long b){
        return mod(mod(a)*mod(b));
    }
    long long minu(long long a, long long b){
        return mod(mod(a)-mod(b));
    }

ll power(ll a,ll b)
{
    if(b==1)
    return a;

    ll smallans = power(a,b/2);
    smallans = ((smallans)%MOD * (smallans)%MOD)%MOD;
    if(b&1)
    smallans = ((a)%MOD * (smallans)%MOD)%MOD;

    return smallans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n;
    cin>>n;

    //ll ans =(((power(10LL,n)%MOD - power(9LL,n)%MOD)%MOD - power(9LL,n)%MOD)%MOD + power(8LL,n)%MOD)%MOD;
ll ans=minu(add(power(10LL,n),power(8LL,n)),mul(2LL,power(9LL,n)));
    cout<<ans;
    return 0;
}