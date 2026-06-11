#include<bits/stdc++.h> 
using namespace std; 
#define ll long long 
#define sort(v) sort(v.begin(),v.end()) 
#define pb push_back
/*
ll ar[1000000+9]={0}; 
vector<ll>v;
void seiv() { 
ll n=1000000,i,j; 
ar[1]=1; 
for(i=4;i<=n;i+=2)ar[i]=1; 
for(i=3;i<=n;i+=2) 
{ if(ar[i]==0) 
{ for(j=i*i;j<=n;j+=i*2)ar[j]=1; }
                
 } 
    for(i=2;i<=2244;i++){if(ar[i]==0)v.pb(i);}}*/
int main()
{
ll a,b,c,d,i,j,k,l;
cin>>a>>b;
if(a>=b)
  {
    for(i=1;i<=a;i++)cout<<b;
  }
        else 
        {
        for(i=1;i<=b;i++)cout<<a;
}
 }