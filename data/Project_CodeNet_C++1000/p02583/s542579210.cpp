#include <bits/stdc++.h>
#include <iomanip>
#include <algorithm>
#define ll long long
#include <unordered_map>
using namespace std;

int main() {
  ll N, cnt = 0;
  cin >> N;
  vector<ll> L(N), T(3);
  for(ll i = 0; i < N; i++) cin >> L.at(i);
  
  for(ll i = 0; i < N - 2; i++) {
    for(ll j = i + 1; j < N - 1; j++) {
      for(ll k = j + 1; k < N; k++) {
        if((L.at(i) != L.at(j)) && (L.at(i) != L.at(k)) && (L.at(j) != L.at(k))) {
          T.at(0) = L.at(i);
          T.at(1) = L.at(j);
          T.at(2) = L.at(k);
          sort(T.begin(), T.end());
          if(T.at(0) + T.at(1) > T.at(2)) cnt++;
        }
      }
    }
  }
  
  cout << cnt << endl;
}