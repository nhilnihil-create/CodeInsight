#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

ll x = 1e9 + 7; 
const int INF = 1001001001;

bool f(string s) {
  string sr = s;
  reverse(sr.begin(), sr.end());
  if (sr == s) return true;
  else return false;
}

int main() {
  double l;
  cin >> l;
  printf("%.12f\n", l*l*l/27);
  return 0;
}