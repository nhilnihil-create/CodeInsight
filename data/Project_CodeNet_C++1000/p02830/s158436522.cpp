#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  string S, T, ans = "";
  cin >> N >> S >> T;
  
  for (int i = 0; i < N; i++) ans = ans + S[i] + T[i]; 

  cout << ans << endl;;
}