#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
//  int s, t;
  int64_t K;
  cin >> N >> M >> K;
  vector<int64_t> A(N+1);
  A.at(0)=0;
  for (int i = 1; i < N+1; i++) {
    cin >> A.at(i);
    A.at(i) += A.at(i-1);
  }
  vector<int64_t> B(M+1);
  B.at(0)=0;
  for (int i = 1; i < M+1; i++) {
    cin >> B.at(i);
    B.at(i) += B.at(i-1);
  }
  int max=0;
  int best=M;
  bool f=false;
  for (int i=0; i<N+1; i++){
//    cout << "i=" << i << endl;
    for (int j=best; j>=0; j--){
//          cout << "j=" << j << endl;
      if(A.at(i)+B.at(j) <= K){
//        cout << A.at(i) << " " << i << " " << B.at(j) << " " << j << " " << K << endl;
        best=j;
        f=true;
        break;
      }
    }
    if (f && i+best > max){
      max=i+best;
//      s=i;
//      t=best;
//      cout << s << " " << t << endl;
    }
    f=false;
  }
  cout << max << endl;
}
