#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int main(){
  int N, M, Q;
  cin >> N >> M >> Q;
  int A[60], B[60], C[60], D[60];
  rep(i, Q){
    cin >> A[i] >> B[i] >> C[i] >> D[i];
    A[i]--;
    B[i]--;
  }

  vector<int> X(N+M-1, 1);
  rep(i, M-1) X[i] = 0;

  int ans = 0;
  do{
    int cnt = 1;
    vector<int> Y;
    rep(i, X.size()){
      if (X[i]==1) Y.push_back(cnt);
      else cnt++;
    }
    int sums = 0;
    rep(i, Q){
      if (Y[B[i]] - Y[A[i]] == C[i]) sums += D[i];
    }
    ans = max(ans, sums);

  }
  while (next_permutation(X.begin(), X.end()));

  cout << ans << endl;
}
