#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int main(){
  int N, M;
  cin >> N >> M;
  int A[M];
  rep(i, M) cin >> A[i];

  int sums = 0;
  rep(i, M) sums += A[i];
  cout << max(-1, N - sums) << endl;
}
