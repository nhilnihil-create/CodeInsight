#include <bits/stdc++.h>

using namespace std;

int N, K;
long long maxA = -1;
vector<long long> A;

bool search(long long X) {
  long long sum = 0;
  
  for (int i = 0; i < N; i++) {
    sum += A[i] / X;
    
    if (A[i] % X == 0) {
      sum--;
    }
  }
  
  return sum <= K;
}

int main() {
  cin >> N >> K;
  
  for (int i = 0; i < N; i++) {
    long long inA;
    
    cin >> inA;
    
    A.push_back(inA);
    maxA = max(maxA, inA);
  }
  
  long long left = 0, right = maxA;
  
  while (abs(right - left) > 1) {
    long long mid = (left + right) / 2;
    
    if (search(mid)) {
      right = mid;
    } else {
      left = mid;
    }
  }
  
  cout << right << endl;
  
  return 0;
}