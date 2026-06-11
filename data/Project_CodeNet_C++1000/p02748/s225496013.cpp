#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>

#define pb push_back
#define mp make_pair

using namespace std;

typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef unsigned long long ull;
typedef long long ll;

int main() {
  int a, b, m;
  cin >> a >> b >> m;

  vi va;
  vi vb;
  
  int min_a = 100005;
  for (int i = 0; i < a; ++i) {
    int k;
    cin >> k;

    va.pb(k);
    min_a = min(min_a, k);
  }

  int min_b = 100005;
  for (int i = 0; i < b; ++i) {
    int k;
    cin >> k;

    vb.pb(k);
    min_b = min(min_b, k);
  }

  int res = min_a+min_b;

  for (int i = 0; i < m; ++i) {
    int xi, yi, ci;
    cin >> xi >> yi >> ci;
    xi--; yi--;

    res = min(res, va.at(xi)+vb.at(yi)-ci);
  }

  cout << res << endl;
  return 0;
}
