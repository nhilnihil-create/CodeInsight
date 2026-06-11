#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define rep2(i, s, n) for (int i = (s); i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
int main() {
  int n;
  cin >> n;
  map<string, int> mp{};
  rep(i, n) {
    string s;
    cin >> s;
    mp[s]++;
  }
  cout << mp.size() << endl;
  return 0;
}