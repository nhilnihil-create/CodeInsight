#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  ll n;
  cin >> n;
  vector<ll> vec(n+1);
  for(ll i=0; i<=n; i++) cin >> vec[i];
  ll res = 0;
  ll current = 0;
  vector<ll> mx(n+1);
  if(n == 0 && vec[0] != 1){
    cout << -1 << endl;
    return 0;
  }
  if(n != 0 && vec[0] != 0){
    cout << -1 << endl;
    return 0;
  }
  for(ll i=0; i<=n; i++){
    if(i == 0) mx[i] = 1;
    else{
      if((mx[i-1]-vec[i-1])*2 < vec[i]){
        cout << -1 << endl;
        return 0;
      }
      mx[i] = min((mx[i-1]-vec[i-1])*2, (ll)1000000000000000000);
    }
  }
  for(ll i=n; i>=0; i--){
    if(i == n){
      current += vec[i];
      res += current;
    }else{
      current = min(vec[i]+current, mx[i]);
      res += current;
    }
  }
  cout << res << endl;
  return 0;
}