#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int D[N];
  rep(i, N){
    cin >> D[i];
  }
  int ans = 0;
  rep(i, N){
    repi(j, i+1, N){
      ans += D[i] * D[j];
    }
  }
  cout << ans << endl;
}
