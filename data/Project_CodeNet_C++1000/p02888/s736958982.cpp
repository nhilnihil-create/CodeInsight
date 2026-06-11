#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;

int main() {
  int N;
  ll ans{};
  cin >> N;
  vector<int> L(N);
  for (int &l: L) cin >> l;
  sort(begin(L),end(L));
  for (int i = 0; i != N; ++i) {
    for (int j = i+1; j < N; ++j) {
      ans += lower_bound(begin(L)+j+1, end(L), L[i]+L[j]) - begin(L)-j-1;
    }
  }
  cout << ans << endl;
}
