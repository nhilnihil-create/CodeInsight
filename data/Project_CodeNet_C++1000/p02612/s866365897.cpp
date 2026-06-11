#include <bits/stdc++.h>
using namespace std;
#define ll long long int
#define run ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);cerr.tie(0);
#define mod 1000000007
#define ms(a,x) memset(a,x,sizeof(a))


ll gcd(ll a, ll b) 
{ 
    if (b == 0) 
        return a; 
    return gcd(b, a % b);  
      
} 


int main()
 {
  run;
 ll n;
 cin>>n;
 if(n%1000==0)
 {
     cout<<0<<endl;
 }
  else
  {
      ll ans=n/1000;
      ans++;
     cout<< 1000*ans-n;
  }
 }