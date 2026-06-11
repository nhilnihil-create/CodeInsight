/* Start coding only after you have clear idea.*/
#pragma GCC optimize(2)
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <iomanip>
#include <set>
using namespace std;
typedef long long ll;
const int N = 2e5 + 11;
#define inf 2000000007
#define mod 1000000007
#define IosF ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)

void D() {
  ll x, res = 0;
  cin >> x;
  string s;
  cin >> s;
  res = x * 100 * (s[0] - 48);
  res += x * 10 * (s[2] - 48);
  res += x * (s[3] - 48);
  res /= 100;
  cout << res << endl;
}
int main() {
    IosF;
 	D();	
	return 0;
}