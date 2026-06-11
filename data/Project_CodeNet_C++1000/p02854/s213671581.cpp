#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;

  ll A[N];
  rep(i,0,N-1) cin >> A[i];

  int i=0, j=N-1;
  ll l=0, r=0;
  while (1) {
    if (l <= r) {
      l += A[i];
      i++;
    } else {
      r += A[j];
      j--;
    }
    if (j < i) break;
  }

  cout << abs(l - r) << endl;
  return 0;
}
