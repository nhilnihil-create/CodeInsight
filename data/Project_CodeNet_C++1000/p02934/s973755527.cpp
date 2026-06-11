#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  double sum=0;
  cin >> N;
  vector<int> A(N);
  for(int i=0;i<N;i++){
    cin >> A.at(i);
    sum+=(double)1/A.at(i);
  }
  cout << fixed << setprecision(10) << 1/sum << endl;
} 