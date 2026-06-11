#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() { 
  string S;
  cin >> S;
  ll K;
  cin >> K;
  int N = S.length();

  ll ans = 0;
  vector<pair<char, ll>> a;
  for (int i = 0; i < N-1; i++) {
    ll temp = 0;
    char x = S[i];
    while (S[i] == S[i+1] && i < N-1) {
      temp++;
      i++;
    }
    a.push_back(make_pair(x, temp+1));
    ans += (temp+1)/2;
  }
  if (N == 1) {
    a.push_back(make_pair(S[0], 1));
  }
  
  if (a.size() == 1) {
    ans = a.front().second*K/2;
  } else {
    ans *= K;
    if (a.front().first == a.back().first) {
      ans += ((a.front().second+a.back().second)/2 - a.front().second/2 - a.back().second/2) * (K - 1);
    }
  }
  
  cout << ans << endl;
  return 0;
}