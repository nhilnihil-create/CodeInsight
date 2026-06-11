#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
  long long n, p;
  string s;
  cin >> n >> p >> s;

  long long res = 0;

  if (p == 2 || p == 5) {
    for (int i = n - 1; i >= 0; i--) {
      if ((s[i] - '0') % p == 0) {
        res += i + 1;
      }
    }
  } else {
    map<int, long long> mp;
    mp[0]++;
    long long cur = 0, b = 1;
    for (int i = n - 1; i >= 0; i--) {
      cur = (cur + (s[i] - '0') * b) % p;
      b = (b * 10) % p;
      res += mp[cur]++;
    }
  }
  cout << res << endl;

  return 0;
}