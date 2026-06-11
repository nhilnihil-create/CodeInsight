#include <bits/stdc++.h>
using namespace std;

int main(){
  int N;
  cin >> N;
  vector<int> P(N);
  vector<int> Q(N);
  for (int i = 0; i < N; i++) cin >> P.at(i);
  for (int i = 0; i < N; i++) cin >> Q.at(i);
  vector<int> A(N);
  for (int i = 0; i < N; i++) A.at(i) = i + 1;
  int cnt = 1, Pn, Qn;
  do{
    if (A == P) Pn = cnt;
    if (A == Q) Qn = cnt;
    cnt++;
   }while(next_permutation(A.begin(), A.end()));
  cout << abs(Pn - Qn) << endl;
}