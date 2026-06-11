#include<bits/stdc++.h>
#define ll long long
#define t ll t; cin>>t; while(t--)
#define fast ios_base::sync_with_stdio(false); cin.tie(NULL);
using namespace std;

int main(void){
  fast;
  // Code from here....
  ll n, x, p;
  cin>>n>>x>>p;
  ll ans = ceil(1.0*n/x);
  ans = ans*p;
  cout<<ans;
}