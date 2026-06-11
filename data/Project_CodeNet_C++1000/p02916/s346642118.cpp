#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int A[N];
  int B[N];
  int C[N-1];
  rep(i, N){
    cin >> A[i];
    A[i]--;
  }
  rep(i, N){
    cin >> B[i];
  }
  rep(i, N-1){
    cin >> C[i];
  }
  int ans=0;
  rep(i, N){
    ans += B[A[i]];
    if (A[i+1] - A[i]==1) ans += C[A[i]];
  }
  cout << ans << endl;
}