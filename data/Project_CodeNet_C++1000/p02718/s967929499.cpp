#include <bits/stdc++.h>
using namespace std;
 
int main() {
  double N,M,sum=0; cin >> N >> M;
  vector<int> A(N);
  bool ans = true;
  
  for(int i=0; i<N; i++) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  sort(A.begin(),A.end());
  reverse(A.begin(),A.end());
  double judge = sum / (4*M);

  for(int i=0; i<M; i++) {
    if(A.at(i) < judge ) ans = false;
  }

  if(ans==true) cout << "Yes" << endl;
  else cout << "No" << endl;
}