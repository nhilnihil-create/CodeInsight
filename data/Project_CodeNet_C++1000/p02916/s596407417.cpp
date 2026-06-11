#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()

int main() {
  int N;
  cin >> N;
  int A[N],B[N],C[N-1];
  rep(i,N) cin >> A[i];
  rep(i,N) cin >> B[i];
  rep(i,N-1) cin >> C[i];
  
  int res = 0;
  int a = -2;
  int b;
  rep(i,N){
    b = A[i]-1;
    if (a+1==b)
      res += C[a];
    res += B[b];
    a = b;
  }
  cout << res << endl;
}