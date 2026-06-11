#include <bits/stdc++.h>
#include <iomanip>
#define ll long long
using namespace std;
 
int main() {
  ll N, exccnt = 0;
  vector<ll> sumcnt(3, 0);
  cin >> N;
  string S;
  cin >> S;
  for(ll i = 0; i < N; i++) {
    if(S.at(i) == 'R') sumcnt.at(0)++;
    else if(S.at(i) == 'G') sumcnt.at(1)++;
    else sumcnt.at(2)++;
  }
  for(ll i = 0; i < N - 2; i++) {
    for(ll j = i + 1; j < N - 1; j++) {
      if((0 <= 2 * j - i) && (2 * j - i < N)) {
        if((S.at(i) != S.at(j)) && (S.at(i) != S.at(2 * j - i)) && (S.at(j) != S.at(2 * j - i))) exccnt++;
      }
    }
  }
  cout << sumcnt.at(0) * sumcnt.at(1) * sumcnt.at(2) - exccnt << endl;
}