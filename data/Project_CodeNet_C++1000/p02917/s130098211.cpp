#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int B[N-1];
  rep(i, N-1){
    cin >> B[i];
  }
  int ans = B[0];
  rep(i, N-2){
    ans += min(B[i], B[i+1]);
  }
  ans += B[N-2];
  cout << ans << endl;
}
