// Code for B - Bite Eating
#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, L;
  cin >> N >> L;
  
  vector<int> A(N);
  for (int i = 1;i <= N; i++) {
    A.at(i - 1) = L + i - 1;
  }

  int sum = 0;
  int amin = 10000000;
  int original = 0;
  vector<int>::iterator itr = A.begin();
  for (; itr != A.end(); itr++) {
    sum += *itr;
    if (abs(*itr) < amin) {
      amin = abs(*itr);
      original = *itr;
    }
  }

  cout << sum - original;

	return 0;
}
