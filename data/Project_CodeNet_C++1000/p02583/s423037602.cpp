#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_triangle(int a, int b, int c) {
  // a <= b <= c
  if (a == b || b == c) {
    return false;
  } 
  if (a + b > c) {
    return true;
  } 
  return false;
}

int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) {
    cin >> L[i];
  }
  sort(L.begin(), L.end());
  
  int ans = 0;
  for (int i = 2; i < N; i++) {
    for (int j = 1; j < i; j++) {
      for (int k = 0; k < j; k++) {
        if (is_triangle(L[k], L[j], L[i])) {
          ans++;
        }
      }
    }
  }
  cout << ans;
}
