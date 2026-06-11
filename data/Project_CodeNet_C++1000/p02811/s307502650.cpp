#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, X;
  cin >> K >> X;
  
  int sum = 500 * K;
  if (sum >= X) {
    cout << "Yes" << endl;
  }
  else {
    cout << "No" << endl;
  }
}