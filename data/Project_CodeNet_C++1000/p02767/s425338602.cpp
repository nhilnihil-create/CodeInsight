#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  rep(i,N) cin >> A.at(i);
  int ans = 10000*100;
  rep(i,100){
    int n = i + 1;
    int sum = 0;
    rep(j,N){
      sum += (A.at(j) - n) * (A.at(j) - n);
    }
    if(sum <= ans){
    ans = sum;
    }
    else{
      break;
    }
  }
  cout << ans << endl;
}