#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
  int n;
  cin >> n;

  unordered_map<string, int> count;

  rep(i, n) {
    string s;
    cin >> s;

    if (count[s]) {
      count[s]++;
    } else {
      count[s] = 1;
    }
  }

  cout << count.size() << endl;

  return 0;
}
