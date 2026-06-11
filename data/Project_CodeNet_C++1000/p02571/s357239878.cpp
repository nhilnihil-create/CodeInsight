#include <bits/stdc++.h>
#define lli long long int

using namespace std;

int main() {
  std::string S, T;
  std::cin >> S >> T;
  int ans = T.size();
  for (int start = 0; start <= S.size() - T.size(); ++start) {
    int diff = 0;
    for (int i = 0; i < T.size(); ++i) {
      if (T[i] != S[start+i]) {
        diff++;
      }
    }
    ans = min(ans,diff);
  }
  std::cout << ans << std::endl;
}