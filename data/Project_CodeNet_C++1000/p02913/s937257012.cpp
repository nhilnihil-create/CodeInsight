#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e12;
using Graph = vector<vector<int>>;

vector<int> Zalgo( const string &S ){
  int c = 0;
  int N = (int)S.size();
  vector<int> Z(N+10, 0);
  for( int i = 1; i < N; i++ ){
    int l = i-c;
    if( i+Z[l] < c+Z[c] ) Z[i] = Z[l];
    else{
      int j = max(0LL, c+Z[c]-i);
      while( i+j < N && S[j] == S[i+j] ) j++;
      Z[i] = j;
      c = i;
    }
  }
  Z[0] = N;
  return Z;
}

signed main(){
  int N;
  cin >> N;
  string S;
  cin >> S;
  int ans = 0;
  for( int i = 0; i < N; i++ ){
    string T = S.substr(i);
    vector<int> Z = Zalgo(T);
    for( int j = 0; j <= T.size(); j++ ){
      if( Z[j] <= j ) ans = max(ans, Z[j]);
    }
  }
  cout << ans << endl;

}
