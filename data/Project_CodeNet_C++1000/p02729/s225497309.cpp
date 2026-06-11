#include<iostream>
using namespace std;
int main() {
  int N, M;
  cin >> N >> M;
  int sum = 0;
  sum = N * (N - 1) / 2 + M * (M - 1) / 2;
  cout << sum;
}