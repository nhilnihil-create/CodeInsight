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
  	vector<pair<int, int>> a(n);
  	for (int i = 0; i < n; i++)
      	cin >> a[i].ff >> a[i].ss;
  	bool ans = false;
  	for (int i = 2; i < n; i++) {
    	if (a[i].ff != a[i].ss)
        	continue;
      	if (a[i - 1].ff != a[i - 1].ss)
          	continue;
      	if (a[i - 2].ff != a[i - 2].ss)
          	continue;
      	ans = true;
      	break;
    }
  	cout << (ans ? "Yes" : "No");
    return 0;
}