#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M,sum=0; cin >> N >> M;
  vector<int> A(N);
  for(int i=0; i<N; i++) cin >> A.at(i);
  for(int i=0; i<N; i++) sum += A.at(i);
  
  if(N<sum) {
    cout << -1 << endl;
    return 0;
  }
  cout << N-sum << endl;
}