#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
  int A, B, C, K;
  cin >> A >> B >> C >> K;
  int sum = 0;
  if(A >= K){
   sum += K;
  }else{
    sum += A;
    K -= A;
    if(B < K){
      K -= B;
      sum -= K;
    }
  }
  cout << sum << endl;
  return 0;
}