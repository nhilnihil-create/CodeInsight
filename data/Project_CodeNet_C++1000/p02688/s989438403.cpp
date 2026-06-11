#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;


int main(){
  int N, K;
  cin >> N >> K;
  map<int, int> A;
  rep(i, N) A[i] = 0;
  rep(i, K){
    int d;
    cin >> d;
    rep(j, d){
      int a;
      cin >> a;
      a--;
      A[a]++;
    }
  }
  int ans = 0;
  for (auto a : A){
    if (a.second == 0) ans++;
  }
  cout << ans << endl;
}
