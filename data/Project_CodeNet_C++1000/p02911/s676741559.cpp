#include <bits/stdc++.h>
using namespace std;

int main(){
  int64_t N, K, Q;
  cin >> N >> K >> Q;
  vector<int64_t> A(Q);
  for(int i = 0; i < Q; i++){
    cin >> A.at(i);
  }
  vector<int64_t> P(N, K - Q);
  for(int i = 0; i < Q; i++){
    P.at(A.at(i) - 1)++;
  }
  for(int i = 0; i < N; i++){
    if(P.at(i) > 0) cout << "Yes" << endl;
    else cout << "No" << endl;
  }
  return 0;
}