#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

signed main(){
  string S, T;
  cin >> S >> T;

  int N = (int)S.size();

  vector<bool> fg(26);
  Graph ch(26);
  for( int i = 0; i < N; i++ ){
    ch.at(S.at(i)-'a').push_back(i+1);
    fg.at(S.at(i)-'a') = 1;
  }

  int ans = 0;
  for( int i = 0; i < T.size(); i++ ){
    if( fg.at(T.at(i)-'a') == false ){
      cout << -1 << endl;
      return 0;
    }
    auto Iter = upper_bound(ch.at(T.at(i)-'a').begin(), ch.at(T.at(i)-'a').end(), ans%N);
    if( Iter == ch.at(T.at(i)-'a').end() ){
      ans += N-(ans%N)+ch.at(T.at(i)-'a').at(0);
    }else ans += *Iter - ans%N;
  }
  cout << ans << endl;

}
