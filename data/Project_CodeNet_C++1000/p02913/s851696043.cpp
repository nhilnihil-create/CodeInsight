#include <bits/stdc++.h>
#define int long long
#define double long double
using namespace std;
const int MOD = 1000000007;
const int INF = 1e14;
using Graph = vector<vector<int>>;

vector<int> Zalgo( const string& S ){
  int c = 0;
  int n = (int)S.size();

  vector<int> lcp(n, 0);
  for( int i = 1; i < n; i++ ){
    int l = i-c;
    if( i+lcp[l] < c+lcp[c] ) lcp[i] = lcp[l];
    else{
      int j = max(0LL, c+lcp[c]-i);
      while( i+j < n && S[j] == S[i+j] ) j++;
      lcp[i] = j;
      c = i;
    }
  }
  lcp[0] = n;
  return lcp;
}

signed main(){
  int N;
  cin >> N;
  string S;
  cin >> S;

  int ans = 0;
  for( int i = 0; i < N; i++ ){
    string T = S.substr(i);
    vector<int> now = Zalgo(T);
    for( int j = 0; j < T.size(); j++ ){
      if( now[j] <= j ) ans = max(ans, now[j]);
    }
  }
  cout << ans << endl;

}