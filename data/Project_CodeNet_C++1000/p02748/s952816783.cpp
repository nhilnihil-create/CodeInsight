#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B, M;
  cin >> A >> B >> M;
  vector<int> ai(A);
  for (int i=0; i<A; i++) cin >> ai.at(i);
  vector<int> bj(B);
  for (int j=0; j<B; j++) cin >> bj.at(j);
  vector<int> sum(M);

  int xk, yk, ck;
  for (int k=0; k<M; k++) {
  cin >> xk >> yk >> ck;
  sum.at(k) = ai.at(xk-1) + bj.at(yk-1) - ck;
  }
  sort(sum.begin(),sum.end());

  sort(ai.begin(),ai.end());
  sort(bj.begin(),bj.end());
  int sum_min=ai.at(0)+bj.at(0);

  cout << min(sum.at(0), sum_min) << endl;
}