#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll  = long long;

bool is(ll t,ll k,ll n,vector<ll>a,vector<ll>f){
    ll sum= 0;
    for(int i=0;i<n;i++){
        if(a[i]*f[i]>t)
            sum+=a[i]-t/f[i];
    }
        return sum<=k;

}

int main()
{
    ll n,k;
    cin>>n>>k;
    vector<ll>a(n);
    vector<ll>f(n);
    for(int i=0;i<n;i++)cin>>a[i];
      for(int i=0;i<n;i++)cin>>f[i];
      //a[i]*f[i] seconds to complete ith food
      //score is max(a[i]*f[i]) f.a. i
      sort(a.begin(),a.end());
      sort(f.begin(),f.end(),greater<ll>());

      ll lo=0;ll hi = 1000000000010;;
      while(lo<hi){
        ll mid = (lo+hi)/2;
        if(is(mid,k,n,a,f))hi=mid;
        else lo = mid+1;
      }
      cout<<lo;
    return 0;
}
