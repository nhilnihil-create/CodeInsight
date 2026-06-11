#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n,k;
  cin >> n >> k;

  ll p[n];
  for(ll i=0;i<n;i++)cin >> p[i];
  ll s=0,m=0;
  for(ll i=0;i<k;i++)s+=p[i];
  m=max(m,s);

  for(ll i=0;i<n-k;i++){
    s-=p[i];
    s+=p[i+k];
    m=max(m,s);
  }
  double r=m;
  printf("%f",(r+k)/2);



}