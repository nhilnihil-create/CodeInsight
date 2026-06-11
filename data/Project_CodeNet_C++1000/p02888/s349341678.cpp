#include<bits/stdc++.h>
using namespace std;
int main() {
  int N;
  cin >> N;
  vector<int> L(N);
  for(auto& i: L) cin >> i;
  sort(begin(L), end(L));
  auto ans = 0;
  for(auto a=0; a<N; ++a) for(auto b=a+1; b<N; ++b) {
    auto c = lower_bound(begin(L)+b+1, end(L), L[a]+L[b]) - begin(L);
    ans += c - b - 1;
  }
  cout << ans << endl;
}
