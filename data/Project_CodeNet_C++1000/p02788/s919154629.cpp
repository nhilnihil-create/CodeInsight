#include <bits/stdc++.h>
#define int long long
using namespace std;
const int MOD = 1000000007;
using Graph = vector<vector<int>>;

signed main() {
  int N, D, A;
  cin >> N >> D >> A;
  
  vector<pair<int, int>> M(N);
  vector<int> X(N);
  for( int i = 0; i < N; i++ ){
    int H;
    cin >> X.at(i) >> H;
    M.at(i) = make_pair(X.at(i), H);
  }
  sort(M.begin(), M.end());
  sort(X.begin(), X.end());
  
  int ans = 0;
  vector<int> imos(N);
  for( int i = 0; i < N; i++ ){
    
    if( i > 0 ) imos.at(i) += imos.at(i-1);
    int HP = M.at(i).second;
    
    if( HP-imos.at(i) <= 0 ) continue;
    int now = (HP-imos.at(i)+A-1)/A;
    ans += now;
    imos.at(i) += now*A;
    
    auto Iter = upper_bound(X.begin(), X.end(), X.at(i)+2*D);
    int k = Iter - X.begin();
    if( k < N ) imos.at(k) -= now*A;
    
  }
  cout << ans << endl;
    
}
