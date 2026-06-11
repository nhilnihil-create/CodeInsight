#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

int main(){
  ll N, K;
  cin >> N >> K;
  ll x = N % K;
  ll y = K - x;
  cout << min(x, y) << endl;
}
