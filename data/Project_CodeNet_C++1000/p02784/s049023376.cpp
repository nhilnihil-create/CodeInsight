#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int H, N;
  cin >> H >> N;
  long long A[N];
  rep(i, N) cin >> A[i];
  long long sums = 0;
  rep(i, N) sums += A[i];
  if (sums >= H) cout << "Yes" << endl;
  else cout << "No" << endl;
}
