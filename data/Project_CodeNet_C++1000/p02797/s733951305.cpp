#include <bits/stdc++.h>
#define rep(i,cc,n) for(int i=cc;i<=n;++i)
using namespace std;

int main() {
  int N, K, S;
  cin >> N >> K >> S;

  vector<int> A(N, S == pow(10, 9) ? 1 : S+1);
  rep(i,0,K-1) A[i] = S;
  for (auto i : A) cout << i << ' ';
  return 0;
}
