#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define sz(x) int(x.size())
#define show(x) {for(auto i: x){cout << i << " ";} cout << endl;}
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  // 全ての帽子の排他的論理和が0、3種類の数が1/3ずつか、2種類以下か
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> cnt;
  rep(i, N) {
    cin >> A[i];
    cnt[A[i]]++;
  }
  if (cnt[0] == N) {
    puts("Yes");
    return 0;
  }
  if (N % 3 != 0) {
    puts("No");
    return 0;
  }
  vector<int> all;
  for (auto p : cnt) {
    for (int i = 0; i < p.second / (N/3); i++) {
      all.push_back(p.first);
    }
  }
  //show(all);
  if (all.size() == 3 && (all[0] ^ all[1] ^ all[2]) == 0) puts("Yes");
  else puts("No");
  return 0;
}
