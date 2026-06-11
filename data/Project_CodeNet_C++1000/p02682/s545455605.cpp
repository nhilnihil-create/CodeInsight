#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int A, B, C, K;

int main(){
  cin >> A >> B >> C >> K;
  int ans = 0;
  if (K < A) ans += K;
  else{
    ans += A;
    K -= A;
    if (K < B) ans += K;
    else{
      K -= B;
      if (K < C) ans -= K;
      else ans -= C;
    }
  }
  cout << ans << endl;
}
