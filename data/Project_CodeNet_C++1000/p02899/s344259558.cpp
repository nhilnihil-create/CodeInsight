#include <bits/stdc++.h>
using namespace std;

int main() {

  int N;
  cin >> N;
  
  vector<int> A(N), B(N);
  
  for(int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  for(int i = 0; i < N; i++) {
    B.at(A.at(i)-1) = i+1;
  }
 
  for(int i = 0; i < N; i++) {
    cout << B.at(i) << " ";
  } 
  cout << endl;
  
}