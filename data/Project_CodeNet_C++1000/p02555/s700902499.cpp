#include<bits/stdc++.h>
#define ll unsigned long long
#define mx 2009
#define pb push_back
#define mod 1000000007
using namespace std;
void cal(ll n)
{
     ll mem[n];
     mem[0]=1;
     mem[1]=0;
     mem[2]=0;
     ll ans;
     for(ll i=3;i<=n;i++)
     {
        ans=0;
        for(ll j=3;j<=i;j++)
        {
           ans+=mem[i-j]%mod;
        }
        mem[i]=ans%mod;
     }
     cout<<mem[n]%mod<<endl;
    // memset(mem,0,n);
}
int main()
{
     ll n;
     while(cin>>n)
     {
        cal(n);
     }
  return 0;
}
