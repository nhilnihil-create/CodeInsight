#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  ll x;
  cin>>x;
  ll ans = (x/500)*1000;
  x = x%500;
  ans = ans + (x/5)*5;
  cout<<ans;
  
  
  
  
  return 0;}
