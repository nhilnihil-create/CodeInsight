#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  bool ans = true;
  for (int i = 0; i < N; i++) {
  int x;
  cin >> x;
  if(x%2 == 0 && x%3 != 0 && x%5 != 0) ans = false;
  
  }
  puts(ans ? "APPROVED":"DENIED");
}
