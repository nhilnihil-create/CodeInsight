#include <bits/stdc++.h>

using namespace std;
const int N = 3;

char s[N + 5];
int len = 0, cur = 0, res = 0; // cur 表示直到当前的最大值

int main() {
  scanf("%s", s + 1);
  len = strlen(s + 1);
  s[0] = 'S';
  for (int i = 1; i <= len; ++i) {
    if (s[i - 1] == 'R' && s[i] == 'R') res = max(res, ++cur);
    else if (s[i - 1] == 'S' && s[i] == 'R') res = max(res, cur = 1);
    else if (s[i - 1] == 'R' && s[i] == 'S') res = max(res, cur);
  }
  cout << res;
}