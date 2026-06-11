#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;

int main(){
  int N;
  cin >> N;
  int V[N];
  rep(i, N){
    cin >> V[i];
  }
  sort(V, V+N);
  double ans = (V[0]+V[1]) / 2.0;
  rep(i, N-2){
    ans = (ans + V[i+2]) / 2.0;
  }
  cout << ans << endl;
}
