#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD =  1000000007;
const int INF = 1e11;
using Graph = vector<vector<int>>;

signed main(){
  int N, K;
  cin >> N >> K;

  if( K > (N-1)*(N-2)/2 ){
    cout << -1 << endl;
    return 0;
  }

  vector<pair<int, int>> ans;
  for( int i = 2; i <= N; i++ ) ans.push_back({1, i});

  int one = 2; int two = 3;
  for( int i = 0; i < (N-1)*(N-2)/2-K; i++ ){
    ans.push_back({one, two});
    two++;
    if( two > N ){
      one++;
      two = one+1;
    }
  }

  cout << ans.size() << endl;
  for( int i = 0; i < (int)ans.size(); i++ ) cout << ans[i].first << " " << ans[i].second << "\n";

}
