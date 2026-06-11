#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int N;
  cin >> N;
  vector<int> X(N);
  long long max = 0; 
  long long c1, c2, c3; 
  c1 = 0; c2 = 0; c3 = 0;
  for (int i = 0; i < N; i++) {
    cin >> X.at(i);
    c2 += X.at(i); 
    c3 += X.at(i) * X.at(i); 
    if (max < X.at(i)) {
      max = X.at(i);
    }
  }
  long long min = (max - 1)*(max -1) * N; 
  for (int P = 1; P <= max; P++) {
    long long tmp = P * P * N - c2 * P * 2 ;
    if (min > tmp) {
      min = tmp;
    }
  }
  
  cout << min + c3; 
  return 0; 
}