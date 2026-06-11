#include <bits/stdc++.h>
using namespace std;
using ll = int64_t;
#define rep(i,n) for(int i = 0; i < ((int)(n)); i++)   // 0-indexed昇順

int main() {
  ll X, Y, A, B, C;
  cin >> X >> Y >> A >> B >> C;
  vector<ll> R(A), G(B), T(C);
  rep(i,A) cin >> R.at(i);
  rep(i,B) cin >> G.at(i);
  rep(i,C) cin >> T.at(i);
  sort(R.begin(), R.end(), greater<ll>());
  sort(G.begin(), G.end(), greater<ll>());
  rep(i,X) T.push_back(R[i]);
  rep(i,Y) T.push_back(G[i]);
  sort(T.begin(), T.end(), greater<ll>());

  ll sum = 0;
  rep(i, X+Y) {
    sum += T[i];
  }
  cout << sum << endl;
}