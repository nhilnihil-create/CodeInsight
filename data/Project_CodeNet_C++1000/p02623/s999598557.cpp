#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<ll> A(N+1);
  vector<ll> B(M+1);
  int x;
  for(int i=1; i<=N; ++i){
    cin >> x;
    A.at(i) = A.at(i-1) + x;
  }
  for(int i=1; i<=M; ++i){
    cin >> x;
    B.at(i) = B.at(i-1) + x;
  }
  int ans=0, j=M;
  for(int i=0; i<=N; i++){
    if(A.at(i) > K) break;
    while(B.at(j) > K-A.at(i)) --j;
    ans = max(ans, i+j);
  }
  cout << ans << endl;
  return 0;
}