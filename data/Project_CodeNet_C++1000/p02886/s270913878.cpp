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
  int sums = 0;
  rep(i, N){
    sums += D[i];
  }
  int ans = sums * sums;
  rep(i, N){
    ans -= D[i] * D[i];
  }
  cout << ans / 2 << endl;
}
