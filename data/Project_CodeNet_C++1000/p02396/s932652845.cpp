#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <list>
#include <queue>
#include <stack>
#include <string>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
  int s[10000];
  for (int i = 0; i < 10000; i++) {
    cin >> s[i];
    if (s[i] == 0) break;
  }

  for (int i = 0; i < 10000; i++) {
    if (s[i] == 0) break;
    cout << "Case " << i + 1 << ": " << s[i] << endl;
  }
  return 0;
}

