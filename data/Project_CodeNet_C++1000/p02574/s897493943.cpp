#include <iostream>
#include <vector>
using namespace std;
const int MAX_N = 1000001;
int N;
int gcd(int a, int b) {
  if (b == 0) return a;
  return gcd(b, a % b);
}

int main() {
  cin >> N;

  vector<int> A(N);
  vector<int> D(MAX_N, 0);
  
  int g = 0;
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    g = gcd(g, A[i]);
    D[A[i]]++;
  }
 
  // 重複があるかチェック
  bool pairwise = true;
  for (int i = 2; i <= MAX_N; i++) {
    int cnt = 0;
    for (int j = i; j <= MAX_N; j += i) {
      cnt += D[j];
    }
    
    if (cnt > 1) {
      pairwise = false;
      break;
    }
  }
  
  if (pairwise) {
    cout << "pairwise coprime";
    return 0;
  } 
  
  if (g == 1) {
    cout << "setwise coprime";
    return 0;
  }
  
  cout << "not coprime";
}