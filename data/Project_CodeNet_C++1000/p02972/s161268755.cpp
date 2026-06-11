#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,s,n) for(int i = s; i < (int)(n); i++)

vector<ll>divisor(ll n) {
  vector< ll > res;
  for(ll i = 1; i * i <= n; i++) {
    if(n % i == 0) {
      res.emplace_back(i);
      if(i != n / i) res.emplace_back(n / i);
    }
  }
  return res;
}

int main() {
  int n,ans = 0;
  cin >> n;
  vector<int>a(n);
  rep(i,0,n) cin >> a[i];
  vector<int>cnt(n,0);
  vector<bool>in(n,false);
  for(int i = n-1;i >= 0;i--){
    if(cnt[i] != a[i]){
      ans++;
      in[i] = true;
      vector<ll>div = divisor(i+1);
      for(int j = 0;j < div.size();j++) cnt[div[j]-1] = (cnt[div[j]-1]+1)%2;
    }
  }
  cout << ans << endl;
  rep(i,0,n){
    if(in[i]) cout << i+1;
    if(i != n-1) cout << " ";
    else cout << "" << endl;
  }
}