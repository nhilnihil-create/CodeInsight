#include <bits/stdc++.h>
using namespace std;
using ll = long long;

#define rep(i,s,n) for(ll i = (s); i < (n); i++)
#define rep0(i,n) rep(i,0,n)
#define rep1(i,n) rep(i,1,n+1)
#define repR(i,s,n) for(ll i = (n-1); i >= (s); i--)
#define repR0(i,n) repR(i,0,n)
#define repR1(i,n) repR(i,1,n+1)

#define BR "\n"
#define SP " "
#define SHOW(x) for(int i = 0; i < x.size(); i++) { cout << x[i] << SP; } cout << BR;
#define SHOW2(x) for(int j = 0; j < x.size(); j++) { SHOW(x[j]); } cout << BR;
#define fcout cout << fixed << setprecision(18)

int main() {
  int N;
  cin >> N;

  ll last = 1 << N;
  vector<ll> S(last);
  rep0(i, last) cin >> S[i];
  sort(S.begin(), S.end());

  string ans = "Yes";
  vector<ll> child;
  child.push_back(S[last - 1]);
  S[last - 1] = -1;

  rep(i, 1, N + 1) {
    vector<ll> parent = child;
    sort(parent.begin(), parent.end());

    ll idx = last - 1;
    while(parent.size() > 0 && idx >= 0) {
      if (S[idx] != -1 && S[idx] < parent.back()) {
        child.push_back(S[idx]);
        parent.pop_back();
        S[idx] = -1;
      } else {
        idx--;
      }
    }
    if (parent.size() > 0) {
      ans = "No";
      break;
    }
  }

  cout << ans << BR;
  return 0;
}