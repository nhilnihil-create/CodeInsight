#include <iostream>
#include <vector>

using namespace std;

int main() {
  string S;
  cin >> S;
  int n = S.size();
  vector<int> a(n + 1), b(n + 1);
  for (int i = 0; i != n; ++i)
    if (S[i] == '<') a[i + 1] = a[i] + 1;
    else a[i + 1] = 0;
  for (int i = n; i; --i)
    if (S[i - 1] == '>') b[i - 1] = b[i] + 1;
    else b[i - 1] = 0;
  long long ans{};
  for (int i = 0; i <= n; ++i) ans += max(a[i], b[i]);
  cout << ans << endl;
}
