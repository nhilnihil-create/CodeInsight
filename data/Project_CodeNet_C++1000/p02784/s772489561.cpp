#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int H,N;
  cin >> H >> N;
  int A;
  int sum = 0;
  rep(i,N){
    cin >> A;
    sum += A;
  }
  if(H <= sum){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
  return 0;
}