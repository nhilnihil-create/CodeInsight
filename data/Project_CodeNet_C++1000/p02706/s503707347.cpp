#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  int sum = 0, a;
  rep(i, M){
   cin >> a;
    sum += a;
  }
  if(N >= sum) cout << N-sum << endl;
  else cout << -1 << endl;
  return 0;
}