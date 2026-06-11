#include<bits/stdc++.h>
#define rep(i,a,n) for(ll i=a;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
  ll a,b,n;
  cin>>a>>b>>n;
  ll memo;
  if(n>=b)memo=b-1;
  else memo=n;
  cout<<(a*memo)/b - a*(memo/b)<<endl;
  return 0;
}