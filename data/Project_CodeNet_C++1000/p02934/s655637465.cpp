#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  double A[N];
  
  for (int i = 0; i < N; i++) cin >> A[i];
  
  double ans = 0;
  
  for (int i = 0; i < N; i++) ans += 1 / A[i];
  
  cout << fixed << setprecision(10) << 1/ans << endl;
}