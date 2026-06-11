#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main(){
  ll n,a,b;
  cin >>n >>a >>b;
  if((b-a)%2==0) cout << (b-a)/2 << endl;
  else if((b-a)%2!=0){
    ll ans = min(a-1, n-b)+1+(b-a-1)/2;
    cout << ans << endl;
  }
  return 0; 
}