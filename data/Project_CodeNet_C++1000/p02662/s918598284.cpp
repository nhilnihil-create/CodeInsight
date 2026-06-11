#include<bits/stdc++.h>
#define mod 998244353ll
#define ll long long
using namespace std;
ll mem[3003][3003], ara[3003], s, n;
ll dp(int pos, int sum)
{
    if(sum>s)return 0;
    if(pos==n)return (sum==s);
    if(mem[pos][sum]!=-1)return mem[pos][sum];
    return mem[pos][sum]= (2ll*dp(pos+1, sum)+dp(pos+1, sum+ara[pos]))%mod;
}
int main()
{
    scanf("%lld %lld", &n, &s);
    for(int i=0; i<n; i++)scanf("%lld", &ara[i]);
    memset(mem, -1, sizeof mem);
    printf("%lld\n", dp(0, 0));
    return 0;
}
