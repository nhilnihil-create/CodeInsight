#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  string S, S_inv, T1, T1_inv, T2, T2_inv;
  cin >> S;
  S_inv = S;
  int N = S.size();
  reverse(S_inv.begin(), S_inv.end());
  T1 = S.substr(0, (N-1)/2);
  T1_inv = T1;
  reverse(T1_inv.begin(), T1_inv.end());
  T2 = S_inv.substr(0, (N-1)/2);
  T2_inv = T2;
  reverse(T2_inv.begin(), T2_inv.end());
  if (S==S_inv && T1==T1_inv && T2==T2_inv) cout << "Yes" << endl;
  else cout << "No" << endl;
}