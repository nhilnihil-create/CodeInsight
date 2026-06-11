#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repi(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
  return b != 0 ? gcd(b, a % b) : a;
}

int main(){
  int K;
  ll sums = 0;
  cin >> K;
  rep(i, K){
    rep(j, K){
      rep(k, K){
        sums += gcd(gcd((i+1), (j+1)), (k+1));
      }
    }
  }
  cout << sums << endl;
}
