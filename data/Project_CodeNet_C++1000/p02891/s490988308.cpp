#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  string s;
  ll K;
  cin >> s >> K;
  ll N = s.size();
  ll in = 1;
  vector<ll> seq;
  for (ll i = 1; i < N; i++) {
    if (s[i-1] == s[i]) in += 1;
    else {
      seq.push_back(in);
      in = 1;
    }
  }
  seq.push_back(in);
  ll RS = seq.size();
  if (RS == 1) {
    cout << N*K/2;
    return 0;
  }
  
  ll rep = 0;
  for (ll i = 1; i < RS-1; i++) rep += seq[i]/2*K;
  if (s[0] == s[N-1]) rep += seq[0]/2+seq[RS-1]/2+(seq[0]+seq[RS-1])/2*(K-1);
  else rep += seq[0]/2*K+seq[RS-1]/2*K;
  
  cout << rep << endl;
}