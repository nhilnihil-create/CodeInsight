#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i, n) for(int i = 0;i < (int)(n);i++)

int main() {
  int N;
  cin >> N;
  ll S = 0;
  string s;
  map<map<char, int>, ll> v;
  REP(i, N) {
    cin >> s;
    map<char, int> a;
    REP(j, 10) a[s[j]]++;
    v[a]++;
  }
  for(auto it = v.begin();it != v.end();it++) {
    S += (it->second) * (it->second - 1) / 2;
  }
  cout << S << endl;
}