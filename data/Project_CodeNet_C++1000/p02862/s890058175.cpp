#include <bits/stdc++.h>
#include <vector>
#include <string>
#include <iomanip>
#include <math.h>
#include <algorithm>
#define hmm "\n"
#define test() int t; cin>>t; while(t--)
#define ll long long int
#define ull unsigned long long
#define fastIO ios_base::sync_with_stdio(false); cin.tie(NULL);

#define mod 1000000007ll
using namespace std;
ll fact[2000006];
ll bigmod(ll b, ll p)
{
    if(!p)return 1ll;
    ll ret= bigmod(b, p/2);
    ret= (ret*ret)%mod;
    if(p&1ll)return ret= (ret*b)%mod;
    return ret;
}
ll ncr(ll n, ll r)
{
    ll nume= fact[n];
    ll deno= (fact[n-r]*fact[r])%mod;
    return (nume*bigmod(deno, mod-2))%mod;
}
int main()
{
    fastIO
    fact[0]= 1ll;
    for(ll i=1; i<=2000000; i++)
    fact[i]= (fact[i-1]*i)%mod;
    int n, m, cnt= 0;
    scanf("%d %d", &n, &m);
    if(n<m)swap(n, m);
    int tot= (n+m)/3;
    while(n>0 && m>0 && 2*n>m)n--, n--, m--, cnt++;
    if(2*n==m)printf("%lld\n", ncr(tot, cnt));
    else puts("0");
    return 0;
}