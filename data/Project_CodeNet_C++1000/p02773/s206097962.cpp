#include<bits/stdc++.h>

using namespace std;
using ll = long long;
#define rep(i,n) for (int i = 0; i < (int)n; i++)

const int inf = 1'000'000'000;

int main() {
  map<string, int> memo;
  int n;

  cin >> n;
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    // mapのキーは一意の値しか取れない
    memo[s] += 1;
  }

  int maxv = 0;
  for (const auto &x : memo) {
    int v = x.second;
    if (v > maxv) maxv = v;
  }
  // 頻度が最大のものが複数あった場合にも対応可能なように
  for (auto it = memo.begin(); it != memo.end(); it++) {
    // itはイテレータなので、キーか値かを選択する
    if (it->second == maxv) {
      cout << it->first << endl;
    }
  }
}
