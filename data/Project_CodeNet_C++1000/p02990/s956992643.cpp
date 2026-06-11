#include <iostream>
#include <bits/stdc++.h>
#define ll long long
#define inf 1000000000000000000
#define norm 0
#define mod 1000000007
#define IO                    \
	ios_base::sync_with_stdio(false); \
	cin.tie(NULL);                    \
	cout.tie(NULL);
using namespace std;
ll fact[3000];
ll invfact[3000];
ll faspow(ll base, ll pow)
{
    if(pow==0)return 1;
    else if (pow ==1)return base;
    ll x=faspow(base,pow/2.0);
   x=(((x)%mod)*((x)%mod))%mod;
    if(pow%2)x*=(base%mod);
    x%=mod;
    return x;
}
ll inv(ll x)
{
    return faspow(x,mod-2);
}
void fill()
{
    fact[0]=1;
    invfact[0]=inv(fact[0]);
    for(int i=1;i<2050;i++)
    {
        fact[i]=((fact[i-1])*(i))%mod;
    }
}
ll ncr(ll n,ll r)
{
    ll a=fact[n],b=inv(fact[n-r]),c=inv(fact[r]);
    //cout<<a<<" "<<b<< " "<<c<<endl;
    return (a*b%mod*c%mod)%mod;
}
ll sss[2005][2005];
ll ss(ll num , ll dig)
{
    if(dig==0)return 1;
    if(sss[num][dig]!=-1)return sss[num][dig];
    ll res=0;
    for(int i=0;i<=dig;i++)
    {
        res+=ss(num-i,dig-1);
    }
    return sss[num][dig]= res;
}
int main()
{
    IO
    memset(sss,-1, sizeof(sss));
    fill();
    ll n,k;
    cin>>n>>k;
    for(int i=1;i<=k;i++)
    {
        ll num=ncr(k-1,i-1);
        ll add=i-1;
        ll freeseg=n-k;
        ll num2=ncr(freeseg+1,i);
       // cout<<num2<<endl;
        cout<<(num*num2)%mod<<endl;
    }
    return 0;
}

