#include <bits/stdc++.h>
using namespace std;

int main() {
  long long X, sum=100, count=0;
  cin >> X;
  
  while(X>sum) {
  long long intr = sum * 1 / 100;
  sum += intr;
  count++;
  }
  cout << count << endl;
}