#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll N,K;
  cin >> N >> K;
  cout << ll(min(N%K,abs(N%K-K))) << endl;
  return 0;
}