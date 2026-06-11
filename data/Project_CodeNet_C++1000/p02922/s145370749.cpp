#include <bits/stdc++.h>
using namespace std;

int main() {
  int A, B;
  cin >> A >> B;
  int N = 1;
  int count = 0;
  while (N < B) {
    N += A-1;
    count++;
  }
  cout << count << endl;
}