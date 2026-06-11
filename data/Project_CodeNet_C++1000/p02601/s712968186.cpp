#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int A,B,C,K; cin >>A >>B >>C >>K;
  string ans="No";
  rep(i,0,K+1) {
    if (B>=C) {C*=2;}
    else if (A>=B) {B*=2;}
    else {ans="Yes";}
  }
  cout <<ans <<endl;
  return 0;
}
