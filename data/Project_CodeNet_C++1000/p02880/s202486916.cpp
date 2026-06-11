#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define sort(v) sort(v.begin(),v.end())
#define pb push_back
/*
ll ar[10000+9]={0};
void seiv()
{
ll n=10000+9,i,j;
ar[1]=1;
for(i=4;i<=n;i+=2)ar[i]=1;
for(i=3;i<=n;i+=2)
{
if(ar[i]==0)
{
for(j=i*i;j<=n;j+=i*2)ar[j]=1;
}
}
}*/
int main()
{
    ll a=0,b=0;ll c;
  cin>>a;c=a;
 for(ll i=2;i<=9;i++)
{if(a%i==0)c=a/i;
        
    }
  // cout<<c<<endl;
if(c>9)cout<<"No\n";
else cout<<"Yes\n";
 }