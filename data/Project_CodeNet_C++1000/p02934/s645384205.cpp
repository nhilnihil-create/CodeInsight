#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  
  vector<int>A(N);
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
  }

  double B = 0;
  for (int i = 0; i < N; i++) {
    B += 1.0/A.at(i);
  }
  printf("%.8lf\n", 1/B);
}
  
  