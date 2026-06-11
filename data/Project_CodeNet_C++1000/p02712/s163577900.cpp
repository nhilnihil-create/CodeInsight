#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin >> N;
  ll ans = 0;
  rep(i, N){
    if ((i+1) % 3 != 0 && (i+1) % 5 != 0) ans += i + 1;
  }
  cout << ans << endl;
}