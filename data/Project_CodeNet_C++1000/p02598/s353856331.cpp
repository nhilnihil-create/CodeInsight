#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define chmin(x,y) x = min(x,y)

int N,K;


// index が条件を満たすかどうか
bool isOK(int mid, vector<int> A) {
  int cnt = 0;
  rep(i,N) {
    cnt += (A[i] -1) / mid;
  }
  
  if ( cnt <= K ) 
    return true;
  else 
    return false;
}

// 汎用的な二分探索のテンプレ
int binary_search(vector<int> A) {
  int ng = 0; 
  int ok = (int)(1e9+1); 

  /* ok と ng のどちらが大きいかわからないことを考慮 */
  while (abs(ok - ng) > 1) {
    int mid = (ok + ng) / 2;

    if (isOK(mid, A)) ok = mid;
    else ng = mid;
  }
  return ok;
}

int main() {
  cin >> N >> K;
  vector<int> A(N,0);
  rep(i,N) { cin >> A.at(i); }
  int ans = binary_search(A);
  cout << ans << endl;
  return 0; 
}