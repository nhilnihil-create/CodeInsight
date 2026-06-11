#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M; cin >> N >> M;
  vector<int> a(M); for (int i =0; i<M; i++) cin >> a.at(i);
  vector<long> f(N+1);
  vector<bool> check(N+1,false);
  for (int i =0; i<M; i++) {
    check.at(a.at(i)) =true;
  } 
  f.at(0) = 1;
  if (check.at(1)) {
    f.at(1) = 0;
  } else {
    f.at(1) = 1;
  }
  if (N >= 2 && check.at(2)) f.at(2) = 0;
  for (int i =2; i<=N; i++) {
    if (N >= 2 && check.at(i) == true) continue;
    f.at(i) = f.at(i-1) + f.at(i-2);
    f.at(i) %= 1000000007;
  }
  cout << f.at(N) % 1000000007 << endl;
}