#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  ll N;
  cin >> N;
  vector<ll> A(N);
  rep(i,N) cin >> A.at(i);
  sort(A.begin(),A.end());
  rep(i,N-1){
    if(A.at(i) == A.at(i+1)){
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
  return 0;
}