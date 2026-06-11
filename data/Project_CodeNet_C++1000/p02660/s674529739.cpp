#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;

int main(){
  ll n;
  cin >> n;

  vector<pair<ll, int>> vec;
  for (ll i=2; i*i<=n; i++){
    int x = 0;
    while (n % i == 0){
      n /= i;
      x++;
    }
    if (x != 0) vec.emplace_back(i, x);
  }
  if (n != 1) vec.emplace_back(n, 1);

  int ans = 0;
  for (auto ele : vec){
    int x = ele.second;
    int b = 1;
    while (b <= x){
      x -= b;
      b++;
      ans++;
    }
  }

  cout << ans << endl;
  return 0;
}
