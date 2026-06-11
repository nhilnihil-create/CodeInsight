#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
 
int main() {
  int E;
  int A, B;
  cin >> A >> B;
  vector<int> vec(A);
  rep(i,B){
    int C = 0;
    cin >> C;
    rep(i,C){
      int D = 0;
      cin >> D;
      vec[D-1] = 1;
    }
  }
  rep(i,A){
    if(vec[i] == 0){
      E++;
    }
  }
  cout << E << endl;
 
 
 
  return 0;
}