#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M,K;
  cin >> N >> M >> K;
  vector<long long>A(N);
  vector<long long>B(M);
  vector<long long>C(N);
  vector<long long>D(M);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    if (i == 0){
      C.at(i) = A.at(i);
    }
    else {
      C.at (i) += C.at(i-1) + A.at(i);
    }
  }
  int counta = 0;
  for (int i = 0; i < N; i++) {
    C.at(i) = K - C.at(i); 
    if (C.at(i) < 0){
      break;
    }
    counta++;
  }
  
  for (int i = 0; i < M; i++) {
    cin >> B.at(i);
    if (i == 0){
      D.at(i) = B.at(i);
    }
    else {
      D.at (i) += D.at(i-1) + B.at(i);
    }
  }
  int countb = 0;
  for (int i = 0; i < M; i++) {
    if (D.at(i) > K ){
      break;
    }
    countb++;
  }
  
  int MAX = max(counta,countb);
  for (int i = 0; i < counta; i++) {
    for (int j = countb-1; j >= 0; j--) {
      if (C.at(i) >= D.at(j)){
        if (i + j + 2 > MAX){
          MAX = i + j + 2;
        }    
        countb = j+1;
        break;
      }
    }
  }
  cout << MAX << endl;
}

  