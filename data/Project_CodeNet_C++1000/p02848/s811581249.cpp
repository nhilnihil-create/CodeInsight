#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#define ll long long
#define rep(i, a, b) for(ll i = (ll)a; i < (ll)b; i++)
using namespace std;

int main() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  rep(i, 0, n) {
    rep(j, 0, (int)s.size()) {
      if(s[j] == 'Z') s[j] = 'A';
      else s[j]++;
    }
  }
  cout << s << "\n";
}