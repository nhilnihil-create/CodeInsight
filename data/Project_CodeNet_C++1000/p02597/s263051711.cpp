#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>; // グラフ型
typedef long long ll;
#define _GLIBCXX_DEBUG
#define rep(i, n) for(int i = 0; i < (n); ++i)




int main() {
  ll N;
  cin >> N;
  string S;
  cin >> S;
  //vector<ll> a(N);
  //vector<vector<int>> data(3, vector<int>(4));

  ll num_r = 0;
  ll num_w = 0;
  ll ans = 0;

  rep(i, S.size()){
    if(S.at(i) == 'R')num_r++;
    else num_w++;
  }
  
  rep(i, num_r){
    if(S.at(i) == 'W')ans++;
  }


  cout << ans << endl;

  return 0;
}
