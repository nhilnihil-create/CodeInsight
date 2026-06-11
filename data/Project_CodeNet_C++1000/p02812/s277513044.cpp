#include <bits/stdc++.h>
using namespace std;

int main() {
  size_t N;
  string S;
  cin >> N;
  cin >> S;
  int ans{};
  for (size_t pos{}; (pos = S.find("ABC", pos)) != string::npos; ++ans, pos += 3)
    ;

  cout << ans << endl;
  return 0;
}
