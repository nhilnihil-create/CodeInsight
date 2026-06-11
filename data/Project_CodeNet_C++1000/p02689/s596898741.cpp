#include <bits/stdc++.h>
using namespace std;

int main(){
  int N, M;
  cin >> N >> M;
  
  vector<int> H(N);
  vector<int> high(N, 1);
  for (int i=0 ; i<N ; i++){
    cin >> H.at(i);
  }
  
  vector<int> A(M);
  vector<int> B(M);
  for (int i=0 ; i<M ; i++){
    cin >> A.at(i) >> B.at(i);
    if (H.at(A.at(i)-1) > H.at(B.at(i)-1))
      high.at(B.at(i)-1) = 0;
    else if (H.at(A.at(i)-1) < H.at(B.at(i)-1))
      high.at(A.at(i)-1) = 0;
    else{
      high.at(A.at(i)-1) = 0;
      high.at(B.at(i)-1) = 0;
    }
  }
  
  int ans = 0;
  for (int i=0 ; i<N ; i++){
    if (high.at(i) == 1)
      ans++;
  }
  cout << ans << endl;
}