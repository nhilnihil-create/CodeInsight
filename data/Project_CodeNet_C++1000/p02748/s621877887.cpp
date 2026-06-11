#include <bits/stdc++.h>
using namespace std;

int main() {
  
  int A, B, M; cin >> A >> B >> M;
  
  vector<int> vecA(A); vector<int> vecB(B);
  
  int minA = pow(10, 5) + 1; int minB = pow(10, 5) + 1;
  
  for (int i = 0; i < A; i++) {
    cin >> vecA[i];
    minA = min(minA, vecA[i]);
  }
  
  for (int i = 0; i < B; i++) {
    cin >> vecB[i];
    minB = min(minB, vecB[i]);
  }
  
  int minSum = minA + minB;
  
  for (int i = 0; i < M; i++) {
    
    int x, y, c; cin >> x >> y >> c;
    
    int tmpSum = vecA[x - 1] + vecB[y - 1] - c;
    
    minSum = min(minSum, tmpSum);
    
  }
  
  cout << minSum << endl;
  
}