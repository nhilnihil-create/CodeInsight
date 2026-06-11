#include <iostream>
#include <iomanip>
#include <algorithm>
#include <stdio.h>
#include <string>
#include <vector>
#include <map>
#include <math.h>
#include <numeric>
#include <queue>
#include <stack>
#include <utility>
#include <queue>
#include <set>
#include <unordered_set>
#include <unordered_map>
using namespace std;
typedef long long int lld;
typedef pair<int, int> pii;

int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, A, B, C, D;
  cin >> n >> A >> B >> C >> D;
  A--;
  B--;
  C--;
  D--;
  bool posible = true;
  string s;
  cin >> s;
  for (int i = A; i < C; ++i) {
    if (s[i] == '#' && s[i+1] == '#')
      posible = false;
  }
  for (int j = B; j < D; ++j) {
    if (s[j] == '#' && s[j+1] == '#')
      posible = false;
  }
  if (D < C) {
    // Tendré que saltar a B en algún punto
    // entre B-1 y D
    bool puedoSaltar = false;
    for (int j = B-1; j < D; ++j) {
      if (j < A) continue;
      if (j+2 >= n) continue;
      if (s[j] == '.' && s[j+1] == '.' && s[j+2] == '.') {
        puedoSaltar = true;
      }
    }
    posible &= puedoSaltar;
  }
  cout << (posible ? "Yes" : "No") << "\n";
  return 0;
}