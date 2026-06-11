#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  int kaijouN =1;
  for (int i =1; i<= N; i++) {
    kaijouN *= i;
  }
  vector<int> P(N);
  vector<int> Q(N);
  for (int i =0; i<N; i++) cin >> P.at(i);
  for (int i =0; i<N; i++) cin >> Q.at(i);
  
  vector<int> asceP(N);
  for (int i =0; i<N; i++) asceP.at(i) = P.at(i);
  sort(asceP.begin(),asceP.end());
  
  int numP,numQ, countP, countQ;
  int j =0;
  while (j < kaijouN) {
    int i =0;
    while (i < N) {
      if (asceP.at(i) == P.at(i)) countP++;
      if (asceP.at(i) == Q.at(i)) countQ++;
      i++;
    }
    if (countP == N) numP = j;
    if (countQ == N) numQ = j;
    countP =0; countQ =0; j++;
    next_permutation(asceP.begin(),asceP.end());
  }
  cout << abs(numP - numQ) << endl; 
}