#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M, sum;
  cin >> N;
  M = N/500;
  sum = M*1000;
  N = N%500;
  M = N/5;
  sum = sum + M*5;
  cout << sum << endl;

}