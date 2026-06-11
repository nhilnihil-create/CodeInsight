#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  ll n,ans = 0;
  cin >> n;
  vector<pair<ll,int>> a;
  for(ll i = 2; i * i <= n; i++){
    int cnt = 0;
    while (n%i == 0){
      n/=i;
      cnt++;
    }
    a.emplace_back(i,cnt);
  }
  if (n != 1) a.emplace_back(n,1);
  for(auto au:a){
    int cnt = 1;
    while (au.second >= cnt){
      au.second -= cnt;
      cnt++;
      ans++;
    }
  }
  cout << ans <<endl;
}
