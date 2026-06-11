/**
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⣠⡖⠁⠀⠀⠀⠀⠀⠀⠈⢲⣄⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⠀⣼⡏⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢹⣧⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣸⣿⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⣿⣇⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⣿⣿⡇⠀⢀⣀⣤⣤⣤⣤⣀⡀⠀⢸⣿⣿⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⠀⠀⠀⢻⣿⣿⣔⢿⡿⠟⠛⠛⠻⢿⡿⣢⣿⣿⡟⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠀⣀⣤⣶⣾⣿⣿⣿⣷⣤⣀⡀⢀⣀⣤⣾⣿⣿⣿⣷⣶⣤⡀⠀⠀⠀⠀
⠀⠀⢠⣾⣿⡿⠿⠿⠿⣿⣿⣿⣿⡿⠏⠻⢿⣿⣿⣿⣿⠿⠿⠿⢿⣿⣷⡀⠀⠀
⠀⢠⡿⠋⠁⠀⠀⢸⣿⡇⠉⠻⣿⠇⠀⠀⠸⣿⡿⠋⢰⣿⡇⠀⠀⠈⠙⢿⡄⠀
⠀⡿⠁⠀⠀⠀⠀⠘⣿⣷⡀⠀⠰⣿⣶⣶⣿⡎⠀⢀⣾⣿⠇⠀⠀⠀⠀⠈⢿⠀
⠀⡇⠀⠀⠀⠀⠀⠀⠹⣿⣷⣄⠀⣿⣿⣿⣿⠀⣠⣾⣿⠏⠀⠀⠀⠀⠀⠀⢸⠀
⠀⠁⠀⠀⠀⠀⠀⠀⠀⠈⠻⢿⢇⣿⣿⣿⣿⡸⣿⠟⠁⠀⠀⠀⠀⠀⠀⠀⠈⠀
⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⣼⣿⣿⣿⣿⣧⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀
⠀⠀⠀⠐⢤⣀⣀⢀⣀⣠⣴⣿⣿⠿⠋⠙⠿⣿⣿⣦⣄⣀⠀⠀⣀⡠⠂⠀⠀⠀
⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠉⠀⠀⠀⠀⠀⠈⠉⠛⠛⠛⠛⠋⠁⠀⠀
 *    author:  Daredevil666
 *    institution: IIT Patna
**/
#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#define nl cout<<"\n";
#define ll long long int
#define REP(i,a,n) for(i=a;i<=n;i++)
#define F(i,a,b) for(i=a;i<b;i++)
#define RF(i,b,a) for(i=b;i>=a;i--)
#define IOS  ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const ll mod=1e9+7;
const ll MAXN=1000200;
ll i,j,mask,test;
vector<ll> fact(MAXN),inv(MAXN);
ll power(ll n,ll x)
{
    ll res=1,p=n;
    while(x>0)
    {
        if(x%2==1)
        {
            res=((res%mod)*(p%mod))%mod;
        }
        x/=2;
        p=((p%mod)*(p%mod))%mod;
    }
    return res;
}
void initializer()
{
    fact[0]=1;
    F(i,1,1000001)
    {
        fact[i]=(fact[i-1]*i)%mod;
    }
    RF(i,1000000,1)
    {
        inv[i]=power(fact[i],mod-2);
    }
}
ll C(ll n,ll r)
{
    ll k=(fact[n]*inv[r])%mod;
    k=(k*inv[n-r])%mod;
    return k;
}
int main()
{
IOS
/*#ifndef ONLINE_JUDGE
   freopen("input.txt","r",stdin);
   freopen("output.txt","w",stdout);
#endif // ONLINE_JUDGE*/
initializer();
ll n;
cin>>n;
ll ans=power(10,n)%mod;
ans=(ans-power(8,n))%mod;
if(ans<0)
    ans+=mod;
    ll p=0;
for(i=1;i<n;i++)
{
    p=(p+(C(n,i)*power(8,n-i))%mod)%mod;
    if(p<0)
        p+=mod;
}
p++;
p*=2;
p%=mod;
//cout<<p;nl

ans-=p;
if(ans<0)
    ans+=mod;
cout<<ans;
return 0;
}
