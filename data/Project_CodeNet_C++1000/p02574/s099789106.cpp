#include <bits/stdc++.h>
using namespace std;

int Euclid(int a, int b) {
  return a % b ? Euclid(b , a%b) : b;
}

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  
  vector<bool> prime(1000010, false);
  
  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }
  
  bool cond1 = true, cond2 = false;
  
  // setwiseかどうか
  int temp = A[0];
  for (int i = 1; i < N; i++) {
    
    temp = Euclid(temp, A[i]);
    
    if (temp == 1) {
      cond2 = true;
      break;
    }
  }
  
  
  bool break_cond = false;
  
  // pairwiseかどうか
  for (int i = 0; i < N; i++) {
 
    if (A[i] > 1 && prime[A[i]]) {
      cond1 = false;
      break;
    } else {
      prime[A[i]] = true;
    }
    
    
    for (int j = 2; j * j <= A[i]; j++) {
      if (A[i] % j == 0) {
        if (prime[j]) {
          break_cond = true;
          cond1 = false;
          break;
        } else {
          prime[j] = true;
        }
        
        if (j * j < A[i] && prime[A[i]/j]) {
          break_cond = true;
          cond1 = false;
          break;
        } else {
          prime[A[i]/j] = true;
        }     
      }
    }
    
    if (break_cond) break;
  }
  
  //結論
  if (cond1) {
    cout << "pairwise coprime" << endl;
  } else if (cond2) {
    cout << "setwise coprime" << endl;
  } else {
    cout << "not coprime" << endl;
  }
  

}