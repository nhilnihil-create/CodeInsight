#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) {
  string s;
  cin >> s;

  long long K;
  cin >> K;

  s += s + s;

  long long base = 0;
  bool changed[s.size()];
  changed[0] = false;
  for (int i = 1; i < s.size() / 3; ++i) {
    if (s[i] == s[i - 1] && !changed[i - 1]) {
      ++base;
      changed[i] = true;
    } else
      changed[i] = false;
  }

  long long sec = 0;
  for (int i = s.size() / 3; i <  2 * s.size() / 3; ++i) {
    if (s[i] == s[i - 1] && !changed[i - 1]) {
      ++sec;
      changed[i] = true;
    } else
      changed[i] = false;
  }

  long long thi = 0;
  for (int i = 2 * s.size() / 3; i <  s.size(); ++i) {
    if (s[i] == s[i - 1] && !changed[i - 1]) {
      ++thi;
      changed[i] = true;
    } else
      changed[i] = false;
  }

  long long ret = base;
  if (K - 1 > 0) {
    if ((K - 1) % 2 == 0)
      ret += (sec + thi) * (K - 1) / 2;
    else
      ret += (sec + thi) * (K - 2) / 2 + sec;
  }

  cout << ret << endl;

  return 0;
}