#include<bits/stdc++.h>
 
using namespace std;
 
#define ll long long 
#define ull unsigned long long 
#define ld long double
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define pb push_back
#define er erase
#define line cout<<"\n";
#define mod  1000000007


int main()
{ 
   fast
   ll n;
   cin>>n;
   ll sum=0;
   for(ll x=1; x<n; x++)
   {
       for(ll j=1; j<n; j++)
       {
           if(x*j<n)
           sum++;
           else
           break;
       }
   }
   cout<<sum<<"\n";
return 0;
}
