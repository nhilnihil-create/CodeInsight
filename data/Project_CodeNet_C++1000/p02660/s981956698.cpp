#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;

int main(){
  ll n;
  cin >> n;
  vector<pair<int, ll>> fs;
  for(ll i=2; i*i<=n; i++){
    int kosuu=0;
    while(n%i==0){
      n /= i;
      kosuu++;
    }
    fs.emplace_back(i, kosuu);
  }
  if(n!=1) fs.emplace_back(n, 1);
  int ans=0;
  for(auto p: fs){
    int i=1;
    while(p.second - i >= 0){
      p.second -= i;
      i++;
      ans++;
    }
  }
  cout << ans << endl;
}
