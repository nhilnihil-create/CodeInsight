#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>

using namespace std;

#define PB push_back
#define MP make_pair

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vii;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
  while (true) {
    int n;
    cin >> n;
    if (n == 0) break;
    vi c;
    for (int i = 0; i < n; i++) {
      int tmp;
      cin >> tmp;
      c.PB(tmp);
    }
    sort(c.begin(), c.end());
    int ab = INF;
    for (int i = 1; i < n; i++) {
      if (abs(c[i]-c[i-1]) < ab) {
        ab = abs(c[i]-c[i-1]);
      }
    }
    cout << ab << endl;
  }
  return 0;
}

