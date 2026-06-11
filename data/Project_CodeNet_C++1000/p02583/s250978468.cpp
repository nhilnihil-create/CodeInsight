#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool is_triangle(int a, int b, int c) {
  // a <= b <= c
  if (a == b || a == c || b == c) {
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
  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      for (int k = j + 1; k < N; k++) {
        if (is_triangle(L[i], L[j], L[k])) {
          ans++;
        }
      }
    }
  }
  cout << ans;
}
