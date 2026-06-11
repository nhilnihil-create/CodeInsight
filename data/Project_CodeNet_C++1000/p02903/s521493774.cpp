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
using namespace std;
typedef long long int lld;
typedef long double llf;
typedef pair<lld, lld> pii;


int main()
{
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int n, m, A, B;
  cin >> n >> m >> A >> B;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if ((i < B && j < A) || (i >= B && j >= A)) {
        cout << "1";
      } else {
        cout << "0";
      }
    }
    cout << "\n";
  }
  return 0;
}
