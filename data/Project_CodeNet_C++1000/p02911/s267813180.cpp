#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define REP(i, n) for (int i = 0; i < (int)(n); i++)
#define RREP(i,x) for(int i=((int)(x)-1);i>=0;i--)
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
using ll = long long;
using namespace std;

const long long MOD = 1000000007;
const ll LINF = 1LL << 50;


int main() {
  ll N, K, Q;
  cin >> N >> K >> Q;
  vector<ll> point(N,K-Q);

  for (ll q = 0; q < Q; q++){
    ll indx;
    cin >> indx;
    indx -= 1;
    point[indx] +=1;
  }

  for (ll n = 0; n < N; n++){
    if (point[n] > 0){
      cout << "Yes" << endl;
    } else {
      cout << "No" << endl;
    }
  }

}
