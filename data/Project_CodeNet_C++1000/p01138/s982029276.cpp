#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <functional>
#include <string>
#include <algorithm>
#include <climits>
#include <utility>

#define PRINT(STR) cout << STR << endl;
#define REP(i, n) for (int (i) = 0; (i) < (int)(n); (i)++)
#define REG(i, a, b) for (int (i) = ((int)(a)); (i) < ((int)(b)); i++)
#define ALL(V) (V).begin(), (V).end()
#define SPACE " "

typedef long long ll;

using namespace std;

int nextInt() { int n = -1; cin >> n; return n; }
double nextDouble() { double d = -1; cin >> d; return d; }
ll nextll() { ll n = -1; cin >> n; return n; }
string nextString() { string str; cin >> str; return str; }

// BEGIN //////////////////////////////////////////////////////////////
int main() {
  while (true) {
    int N = nextInt();
    if (N == 0) break;
    int ans = 0;
    int h, m, s;
    int arr[100000] = {0};
    REP(i, N) {
      scanf("%d:%d:%d", &h, &m, &s);
      arr[h * 60 * 60 + m * 60 + s] ++;
      scanf("%d:%d:%d", &h, &m, &s);
      arr[h * 60 * 60 + m * 60 + s] --;
    }

    REP(i, 100000 - 1) {
      arr[i + 1] += arr[i];
      if (ans < arr[i + 1]) {
        ans = arr[i + 1];
      }
    }

    PRINT(ans);
  }
  return 0;
}
// END   //////////////////////////////////////////////////////////////