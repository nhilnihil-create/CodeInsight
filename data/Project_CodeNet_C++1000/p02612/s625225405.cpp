#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  const int kVal = 1000;
  int notes = 1000;
  while (notes < N) {
    notes += kVal;
  }
  cout << notes - N << endl;
}
