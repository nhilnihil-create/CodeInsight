#include <bits/stdc++.h>
#define rep(i,x,n) for(int i=x; i<(int)(n); i++)
#define rep_eq(i,x,n) for(int i=x; i<=(int)(n); i++)
using namespace std;

using ll=long long;

int main() {
  int N; cin >>N;
  vector<int> A(N);
  rep(i,0,N) {
    cin >>A[i];
  }
  sort(A.begin(),A.end());
  string ans="YES";
  rep(i,1,N) {
    if (A[i]==A[i-1]) {
      ans="NO";
      break;
    }
  }
  cout <<ans <<endl;
  return 0;
}
