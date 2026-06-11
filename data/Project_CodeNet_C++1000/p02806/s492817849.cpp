#include <iostream>
#include <string>
using namespace std;
int N, t[55], ans;
string s[55], X;

int main() {
  cin >> N;
  for (int i = 0; i < N; i++) {
    cin >> s[i] >> t[i];
  }
  cin >> X;
  for (int i = N - 1; i >= 0; i--) {
    if (s[i] == X) break;
    ans += t[i];
  }
  cout << ans << endl;
}