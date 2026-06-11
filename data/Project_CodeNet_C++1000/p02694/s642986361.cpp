#include <bits/stdc++.h>
using namespace std;

int main() {
  long long x;
  cin >> x;
  long long ac = 100;
  int year = 0;
  while(ac < x) {
    ac += ac / 100;
    year++;
  }
  cout << year << endl;
}