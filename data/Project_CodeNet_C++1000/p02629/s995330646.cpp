#include <bits/stdc++.h>


int main() {
  int64_t N;
  scanf("%lld", &N);
  std::string ans;
  while (N > 0) {
  N--;
    ans += 'a' + (N%26);
    N /= 26;
  }
  std::reverse(ans.begin(), ans.end());
  printf("%s\n", ans.c_str());
}
