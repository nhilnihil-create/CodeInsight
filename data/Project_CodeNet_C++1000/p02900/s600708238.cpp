#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll gcd(ll a, ll b){ return b ? gcd(b,a%b): a;}

int main(){
  ll a, b;
  cin >> a >> b;
  ll ab = gcd(a, b);
  int ans = 1;
  for(ll i=2; i*i<=ab; ++i){
    if(ab%i == 0){
      ++ans;
      while(ab%i == 0){
        ab /= i;
      }
    }
  }
  if(ab >1) ++ans;
  cout << ans << endl;
}