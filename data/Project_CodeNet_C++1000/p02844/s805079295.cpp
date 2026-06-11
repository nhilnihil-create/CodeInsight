#include <bits/stdc++.h>
using namespace std;

int main(void) {
  int N;
  string S;
  cin >> N >> S;

  int ans = 0;
  for (int i = 0; i < 1000; i++) {
    ostringstream sout;
    sout << setfill('0') << setw(3) << i;
    string text = sout.str();
    int index = 0;
    for (int j = 0; j < S.length(); j++) {
      if (index == 3) break;
      if (text[index] == S[j]) index++;
    }
    if (index == 3) ans++;
  }
  cout << ans << endl;
  return 0;
}