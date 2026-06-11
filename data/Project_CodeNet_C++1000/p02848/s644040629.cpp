#include <bits/stdc++.h>
using namespace std;

const int ALPHABET = 26;

int main() {
  int n;
  string s;
  cin >> n >> s;

  int len = s.size();

  for (int i = 0; i < len; i++) {
    int x = s[i] - 'A';
    x += n;
    x %= ALPHABET;
    s[i] = (x + 'A');
  }

  cout << s << endl;

}