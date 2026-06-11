#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N; vector<int> X(N); int total =0;
  for (int i =0; i<N; i++) {cin >> X.at(i); total += X.at(i);}
  sort(X.begin(),X.end());
  int aveL = total/N ; int aveR = aveL + 1; int ansL =0; int ansR = 0;
  for (int i =0; i<N; i++) {
    ansL += (X.at(i) - aveL) * (X.at(i) - aveL); ansR += (X.at(i) - aveR) * (X.at(i) - aveR);
  }
  cout << min(ansL,ansR) << endl;
}