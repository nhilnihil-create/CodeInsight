#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  int H[N];
  rep(i, N) cin >> H[i];
  sort(H, H+N);
  reverse(H, H+N);
  long long sums = 0;
  repi(i, K, N) sums += H[i];
  cout << sums << endl;
}
