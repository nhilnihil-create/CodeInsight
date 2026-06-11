#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  
  cin >> N;
  
  vector<int>A, B, C;
  
  for (int i = 0; i < N; i++) {
    int inA;
    
    cin >> inA;
    
    A.push_back(inA);
  }
  
  for (int i = 0; i < N; i++) {
    int inB;
    
    cin >> inB;
    
    B.push_back(inB);
  }
  
  for (int i = 0; i < N - 1; i++) {
    int inC;
    
    cin >> inC;
    
    C.push_back(inC);
  }
  
  int aft = 0, bef = -2147483648, sum = 0;
  for (int i = 0; i < N; i++) {
    aft = A[i] - 1;
    
    if (bef + 1 == aft) {
      sum += C[bef];
    }
    
    sum += B[aft];
    bef = aft;
  }
  
  cout << sum << endl;
  
  return 0;
}