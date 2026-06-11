#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  int x = N / 1000;
  if (N % 1000 > 0) x++;
  cout << (x * 1000 - N) << endl;
}