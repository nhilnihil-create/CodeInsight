#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int count = 0;
  
  vector<int> a(N);
  for (int i = 0; i < N; i++) {
    cin >> a.at(i);
  }
  
  int i;
  for (i = 0; i < N; i++) {
    if (a.at(i) == 1){
      count++;
      break;
    }
    else if(i == N-1){
      cout << -1 << endl;
      return 0;
    }
  }
  
  int A = 2;
  for (int j = i+1; j < N; j++) {
    if (a.at(j) == A){
      count++;
      A++;
    }
  }
  cout << N - count << endl;
}
    
    
    
    