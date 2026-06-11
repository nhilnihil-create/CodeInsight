#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N=0, now=0, ans=0;
  cin >> N;
  int H[N];
  rep(i, N){
    cin >> H[i];
  }
  rep(i, N-1){
    if (H[i] >= H[i+1]){
      now++;
      ans = max(ans, now);
    }
    else now = 0;
  }
  cout << ans << endl;
}
