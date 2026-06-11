#include <bits/stdc++.h>
using namespace std;;

int main() {
  int N,M; cin >> N >> M; 
  vector<long> H(N); vector<int> A(M); vector<int> B(M);
  for (int i =0; i<N; i++) cin >> H.at(i);
  for (int i =0; i<M; i++) cin >> A.at(i) >> B.at(i);
  
  vector<bool> check(N,true); 
  for (int i =0; i<M; i++) {
    if (H.at(A.at(i)-1) > H.at(B.at(i)-1)) {
      check.at(B.at(i)-1) = false;
    } else if (H.at(A.at(i)-1) < H.at(B.at(i)-1)) {
      check.at(A.at(i)-1) = false;
    } else {
      check.at(B.at(i)-1) = false;
      check.at(A.at(i)-1) = false;
    } 
  }

  int ans =0;
  for (int i =0; i<N; i++) {
    if (check.at(i)) ans++;
  }
  cout << ans << endl; 
}
  