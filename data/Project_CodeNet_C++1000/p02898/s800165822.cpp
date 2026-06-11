#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N, K;
  cin >> N >> K;
  int H[N];
  int ans = 0;
  rep(i, N){
    cin >> H[i];
  }
  rep(i, N){
    if (H[i] >= K) ans++;
  }
  cout << ans << endl;
}
