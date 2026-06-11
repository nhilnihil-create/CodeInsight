#include <bits/stdc++.h>
#define rep(i,N) for (int i = 0; i < (N); ++i)
#define all(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main(void){
  int N, X;
  cin >> N >> X;
  vector <int> D(N + 1);
  D[0] = 0;
  rep(i,N){
    int x;
    cin >> x;  //L[i]
    D[i + 1] = D[i] + x;
  }

  int ans = 0;
  rep(i,N + 1){
    if (D[i] <= X) ans ++;
  }
  cout << ans << endl;

}
