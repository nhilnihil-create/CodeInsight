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
  rep(i, n+1) cin >> vec[i];
  ll smallest = 0;
  for(ll i=n; i>=0; i--){
    if(i == n){
      if(vec[i] == 0){
        cout << -1 << endl;
        return 0;
      }else{
        smallest += vec[i];
      }
    }else{
      smallest = vec[i] + (smallest+1)/2;
    }
  }
  if(1 < smallest){
    cout << -1 << endl;
    return 0;
  }
  ll res = 0;
  ll current = 0;
  vector<ll> mx;
  rep(i, n+1){
    if(i == 0) mx.push_back(1);
    else mx.push_back(min((mx[i-1]-vec[i-1])*2, (ll)1e18));
  }
  for(ll i=n; i>=0; i--){
    current = min(current+vec[i], mx[i]);
    res += current;
  }
  cout << res << endl;
  return 0;
}
