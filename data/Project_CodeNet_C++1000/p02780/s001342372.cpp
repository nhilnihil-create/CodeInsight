#include <bits/stdc++.h>
#include <iomanip>
#define ll long long
using namespace std;
 
int main() {
  ll N, K, ma = 0, current;
  cin >> N >> K;
  vector<ll> p(N);
  for(ll i = 0; i < N; i++) {
    cin >> p.at(i);
    if(i == K - 1) {
      for(ll j = 0; j < K; j++) {
        ma += p.at(j);
        current = ma;
      }
    }
    else if(i > K - 1) {
      current += - p.at(i - K) + p.at(i);
      if(current > ma) {
        ma = current;
      }
    }
  }
  cout << fixed << setprecision(15) << double(ma + K) / 2 << endl;
}