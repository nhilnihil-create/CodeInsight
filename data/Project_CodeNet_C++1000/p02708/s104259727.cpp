#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll add(ll n,ll a){
  return -a*(a+1)*(2*a+1)/6+a*(a+1)*(n+1)/2+a;
}


int main(){
  ll n,k;
  cin >> n >> k;
  ll ans =0;
  ans+= add(n,n+1);
  ans-= add(n,k-1);
  cout << ans%1000000007;
  
  return 0;
}