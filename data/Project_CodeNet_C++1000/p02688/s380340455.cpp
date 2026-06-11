#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int N, K, d, h = 0;
  cin >> N >> K;  
  vector<int> X(N);
  
  for(int i = 0; i < K; i++) {
    cin >> d;
    for(int j = 0; j < d; j++) {
      vector<int> A(d);
      cin >> A.at(j);
      for(int l = 0; l < N; l++) {
        if(A.at(j) == l+1) X.at(l) = 1;
      }
    }
  }
   
  for(int i = 0; i < N; i++) h += X.at(i);  
  cout << N - h << endl;

}