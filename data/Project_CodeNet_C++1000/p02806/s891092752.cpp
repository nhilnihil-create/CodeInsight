#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N;
  cin >> N;
  vector<string>s(N);
  vector<int>t(N);
  string X;
  int M;
  int sum = 0;
  for (int i = 0; i < N; i++) {
    cin >> s.at(i) >> t.at(i);
  }
  cin >> X;
  
  for (int i = 0; i < N; i++) {
    if (s.at(i) == X){
      M = i;
    }
  }
  
  for (int i = 0; i < N; i++) {
    if (i > M){
      sum += t.at(i);
    }
  }
  cout << sum << endl;
}