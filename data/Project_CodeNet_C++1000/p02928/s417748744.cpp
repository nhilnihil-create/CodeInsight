#include <bits/stdc++.h>
using namespace std;

int main() {
  long int N,K,L;
  L = 1000000007;
  cin >> N >> K;
  vector<int> A(N);
  long int in_count = 0;
  long int out_count = 0;
  for(int i=0; i<N; i++){
    cin >> A.at(i);
  }
  //A内の転倒数の計算
  for(int i=0; i<N-1; i++) {
    for(int j=i+1; j<N; j++){
      if(A.at(i) > A.at(j)) {
        in_count++;
      }
    }
  }
  sort(A.begin(),A.end());
  for(int i=0; i<N-1; i++) {
    for(int j=i+1; j<N; j++){
      if(A.at(i) < A.at(j)) {
        out_count++;
      }
    }
  }
  in_count = (in_count * K) % L;
  out_count = (out_count * ((K * (K-1) / 2) % L)) % L;
  cout << (in_count + out_count) % L << endl;
}
