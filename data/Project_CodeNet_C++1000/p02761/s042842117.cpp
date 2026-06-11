#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M;
  
  vector<int>s(M);
  vector<int>c(M);
  for (int i = 0; i < M; i++) {
    cin >> s.at(i) >> c.at(i);
    if (c.at(i) == 0){
      if (s.at(i) == 1 && N != 1){
        cout << -1 << endl;
        return 0;
      }
    }
    for (int j = 0; j < i; j++) {
      if (s.at(j) == s.at(i) && c.at(i) != c.at(j)){
        cout << -1 << endl;
        return 0;
      }
    }
  }
  
  vector<int>A(N,0);
  for (int i = 0; i < M; i++) {
    A.at(s.at(i)-1) = c.at(i);
  }
  
  if (A.at(0) == 0 && N != 1){
    A.at(0) = 1;
  }
  
  for (int i = 0; i < N; i++) {
    cout << A.at(i);
  }
  cout << endl;
}
 
  