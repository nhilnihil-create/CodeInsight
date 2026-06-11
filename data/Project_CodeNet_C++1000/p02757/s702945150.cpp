#include<bits/stdc++.h>
using namespace std;

#define ll long long int
#define pii pair<int,int>

ll len;

ll fun1(string str,ll prime)
{
    ll ans=0;

    for(ll i=0;i<len;i++){
        if((str[i]- '0')%prime==0) ans+=(i+1);
    }

    return ans;
}

ll bigmod(ll a,ll pr,ll mod)
{
    if(pr==0) return 1ll;
    else if(pr==1) return a%mod;
    ll x=bigmod(a,pr/2ll,mod);
    x=(x*x)%mod;
    if(pr & 1ll) x=(x * a)%mod;
    return x;
}

ll fun2(string str,ll prime)
{
     ll temp[prime+1];
     memset(temp,0,sizeof temp);

     ll ans=0, last=0;
     ll len=str.length();

     for(ll i=0;i<len;i++){
         ll p=last*10ll + (str[i]-'0');
         p=(p%prime)*bigmod(10ll,len-i-1,prime);
         ++temp[(p%prime)];
         last=(last*10ll +(str[i]-'0'))%prime;
     }

     for(ll i=0;i<prime;i++){
         ll x;
         if(temp[i]==0) continue;
         if(i==0) x=((temp[i]*(temp[i]+1))/2ll);
         else x=((temp[i]*(temp[i]-1))/2ll);
         ans+=max(0ll, x);
     }

     return ans;
}

int main()
{
    ll a,b,c,d,p,q;


    string str;
    cin>>len>>p;
    cin>>str;
    ll ans;
    if(p==5 || p==2) ans=fun1(str,p);
    else ans=fun2(str,p);


    cout<<ans<<'\n';
}
