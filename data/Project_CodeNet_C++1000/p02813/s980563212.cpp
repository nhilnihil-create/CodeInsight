#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> P(N); vector<int> Q(N);
  for (int i =0; i<N; i++) cin >> P[i];
  for (int i =0; i<N; i++) cin >> Q[i];
  
  vector<int> numN(N);
  for (int i =0; i<N; i++) numN[i] = i+1;
  int kaijouN = 1;
  for (int i =0; i<N; i++) kaijouN *= i+1;
  
  int numP =0,numQ =0;
  while(next_permutation(P.begin(),P.end())) {
    numP++;
  }
  while(next_permutation(Q.begin(),Q.end())) {
    numQ++;
  }
  
  int ans = abs(numP - numQ);
  cout << ans << endl;  
}