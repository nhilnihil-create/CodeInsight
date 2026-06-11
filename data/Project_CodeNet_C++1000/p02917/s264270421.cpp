#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> B(N-1);
  for (int i =0; i<N-1; i++) {
    int a; cin >> a; B.at(i) = a;
  }
  
  vector<int> A(N);
  int total =0;
  A.at(0) = B.at(0); A.at(N-1) = B.at(N-2);
  total += A.at(0) + A.at(N-1);
  for (int i =1; i<N-1; i++) {
    A.at(i) = min(B.at(i),B.at(i-1));
    total += A.at(i);
  }
  cout << total << endl;
}