#include<bits/stdc++.h>
using namespace std;
#define ll long long int
#define pb                 push_back
#define bug(x)             cerr<<#x<<" "<<x<<endl;
#define T int time;        scanf("%d", &time); while(time--)
    vector<ll>ar;
  bool check(ll i,ll n){
    if(abs(i-n)<=1)return true;
    for(ll ii=n-1; ii>i; ii--)if(ar[ii]<ar[ii-1])
      cout<<ar[ii]<<" ";
    cout<<endl;
    return true;
  }

   int main(){
      ll n,k;
      cin>>n>>k;
      ll ar[n+5];
      for(ll i=0; i<n; i++)cin>>ar[i];
      sort(ar,ar+n);
    ll sum=0;
    for(ll i=0; i<n-k; i++)sum+=ar[i];
      cout<<sum<<endl;

     }
   