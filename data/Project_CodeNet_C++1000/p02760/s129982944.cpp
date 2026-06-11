#include <bits/stdc++.h>
using namespace std;

int main() {
  
  vector<int> A(9);
  for(int i = 0; i < 9; i++) cin >> A.at(i);
  
  int N;
  cin >> N;
  
  vector<int> B(N);
  for(int i = 0; i < N; i++) {
    cin >> B.at(i);
    for(int j = 0; j < 9; j++) {
      if(B.at(i) == A.at(j)) A.at(j) = 0;
    }
  }
  
  int x1, x2, x3, x4, x5, x6, x7, x8, xx;
  x1 = A.at(0) + A.at(1) + A.at(2);
  x2 = A.at(3) + A.at(4) + A.at(5);
  x3 = A.at(6) + A.at(7) + A.at(8);
  x4 = A.at(0) + A.at(3) + A.at(6);
  x5 = A.at(1) + A.at(4) + A.at(7);
  x6 = A.at(2) + A.at(5) + A.at(8);
  x7 = A.at(0) + A.at(4) + A.at(8);
  x8 = A.at(2) + A.at(4) + A.at(6);
  xx = x1*x2*x3*x4*x5*x6*x7*x8;
  
  if(xx == 0) cout << "Yes" << endl;
  else cout << "No" << endl;

}