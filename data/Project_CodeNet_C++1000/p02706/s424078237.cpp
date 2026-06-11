#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  
 int S = 0; 
  vector<int> A(M);
  for(int i = 0; i < M; i++) {
    cin >> A.at(i);
    S += A.at(i);
  }
  
  if(S > N) cout << -1 << endl;
  else cout << N - S << endl;
}