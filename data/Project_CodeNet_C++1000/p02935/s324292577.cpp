#include<bits/stdc++.h>
#define ll long long int

using namespace std;

const ll mod=1000000007;
const ll inf=1e18;

int main(){

  ll n;
  cin >> n;
  double v[n];
  for(int i=0;i<n;i++)cin >> v[i];

  sort(v,v+n);

  double s=v[0];
  for(ll i=1;i<n;i++){
    s=(s+v[i])/2;
  }
  printf("%.8f",s);


}