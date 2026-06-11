#include<bits/stdc++.h>
#define ll long long
#define t ll t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(void){
  fast;
  ll n;
  cin>>n;
  ll a[n];
  for(int i=0; i<n; i++){
    cin>>a[i];
  }
  ll ans = 0;
  for(int i=1; i<n;i++){
    if(a[i]<a[i-1]){
        ans+=(a[i-1]-a[i]);
        a[i]=a[i-1];
    }
  }
  cout<<ans;
  return 0;
}