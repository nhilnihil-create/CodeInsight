#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e18;
using Graph = vector<vector<int>>;

signed main() {
  int N, K, C;
  cin >> N >> K >> C;
  string S;
  cin >> S;

  //前から順に
  vector<int> mae;
  int cnt = C+1;
  for( int i = 0; i < N; i++ ){
    if( S[i] == 'o' && cnt >= C ){
      mae.push_back(i);
      cnt = 0;
    }else cnt++;
  }
  if( mae.size() > K ){
    return 0;
  }

  //後ろから（＝できるだけ遅く）順に選ぶ
  set<int> ushiro;
  cnt = C+1;
  for( int i = N-1; i >= 0; i-- ){
    if( S[i] == 'o' && cnt >= C ){
      ushiro.insert(i);
      cnt = 0;
    }else cnt++;
    if( ushiro.size() == K ) break;
  }

  for( int i = 0; i < K; i++ ){
    if( ushiro.count(mae[i]) ){
      cout << mae[i]+1 << endl;
    }
  }

}