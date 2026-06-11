#include <bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  map<string, int> dict;
  int n;
  cin >> n;
  for(string x; n--; dict[x]++) cin >> x;
  cout << dict.size() << endl;
}
