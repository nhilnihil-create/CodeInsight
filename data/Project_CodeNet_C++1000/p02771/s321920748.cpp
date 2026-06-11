#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using i64 = int64_t;
using ll = long long;
int main() {
  int A,B,C;
  cin >> A >> B >> C;
  if(A == B){
    if(B != C){
      cout << "Yes" << endl;
      return 0;
    }
    else{
      cout << "No" << endl;
      return 0;
    }
  }
  else if(B == C){
    cout << "Yes" << endl;
    return 0; 
  }
  else if(C == A){
    cout << "Yes" << endl;
    return 0;
  }
  else{
    cout << "No" << endl;
    return 0;
  }
  return 0;
}