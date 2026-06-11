#include <bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> B(N - 1);
  for (int i = 0; i < N - 1; i++) {cin >> B.at(i);}
  int A = B.at(0) + B.at(N - 2);
  for (int i = 1; i < N - 1; i++) {A += min(B.at(i - 1), B.at(i));}
  cout << A << endl;
}