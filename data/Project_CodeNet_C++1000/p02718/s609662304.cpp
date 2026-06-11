#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  rep(i, N) cin >> A.at(i);
  int sum = 0;
  for(auto e:A) sum += e;

  int cnt = 0;
  rep(i, N){
   if(A.at(i)*(4*M) >= sum) cnt++;
  }
  if(cnt >= M) cout << "Yes" << endl;
  else cout << "No" << endl;
  return 0;
}


