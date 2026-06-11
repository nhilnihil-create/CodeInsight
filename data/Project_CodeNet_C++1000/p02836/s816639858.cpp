#include<bits/stdc++.h>
using namespace std;
int main () {
  string S;
  cin >> S;
  int N = (int)S.size();
  int ans = 0;
  for (int i = 0; i < N; i ++) {
    int j = N - i - 1;
    if (S[i] != S[j]) ans ++;
  }
  cout << ans / 2 << endl;
}