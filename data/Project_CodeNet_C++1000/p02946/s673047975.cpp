#include <bits/stdc++.h>
using namespace std;

int main() {
  int K, X;
  cin >> K >> X;
  
  int left = max(-1000000, X-K+1);
  int right = min(X+K-1, 1000000);

  for (int i = left; i <= right; i++) {
    cout << i << " ";
  }
  
}
