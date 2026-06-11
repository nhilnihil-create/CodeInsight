#include <iostream>
#include <vector>
#include <cmath>
#include <queue>
#include <deque>
#include <set>
#include <string>
#include <map>
#include <algorithm>
#include <stack>
#include <cstdlib>
#include <iomanip>
#include <ctime>
using namespace std;

using ll = long long;
using ull = unsigned long long;
using ld = long double;
#define ff first
#define ss second

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
   	int n;
  	cin >> n;
  	ll ans = 0;
  	for (int i = 1; i < n; i++) {
      	double cur = sqrt(i);
		for (int j = 1; j < cur; j++)
      		if (i % j == 0)
      			ans += 2;
      	if (floor(cur) == ceil(cur))
          ans++;
    }
  	cout << ans;
    return 0;
}