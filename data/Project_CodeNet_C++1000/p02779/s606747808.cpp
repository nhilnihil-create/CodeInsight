#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  rep(i, N) cin >> A[i];
  sort(A, A+N);
  bool check = true;
  rep(i, N-1){
  if (A[i] == A[i+1]) check = false;
  }
  if (check) cout << "YES" << endl;
  else cout << "NO" << endl;
}
