#include <bits/stdc++.h>
using namespace std;
int main() {
  int N, G = 0;
  cin >> N;
  vector<int> H(N);
  for (int i = 0; i < N; i++) {cin >> H.at(i);}
  for (int i = 0; i < N; i++) {G += H.at(i);}
  vector<int> Z(N - 2);
  int A = H.at(0);
  for (int i = 1; i < N - 1; i++) {
    A += H.at(i);
    if (A - G + A < 0) {Z.at(i - 1) = (A - G + A) * -1;}
    else {Z.at(i - 1) = A - G + A;}
  }
  sort(Z.begin(), Z.end());
  cout << Z.at(0) << endl;
}