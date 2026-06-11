#include<bits/stdc++.h>
#define rep(i,n) for (int i=0; i<n; i++)
#define REP(i,x,n) for (int i=x; i<n; i++)
using namespace std;
using vi = vector<int>;
using vvi = vector<vi>;
using ll = long long;
const int mod = 1'000'000'007;

int main(){
  int n, m;
  cin >> n >> m;
  vector<bool> broken(n+1, false);
  rep(i,m){
    int j;
    cin >> j;
    broken.at(j) = true;
  }
  vi dp(n+2);
  dp.at(n) = 1; 
  for (int i=n-1; i>=0; i--){
    if (broken.at(i)){
      dp.at(i) = 0;
      continue;
    }
    dp.at(i) = (dp.at(i+1) + dp.at(i+2)) % mod;
  }
  cout << dp.at(0) << endl;
  return 0;
}
