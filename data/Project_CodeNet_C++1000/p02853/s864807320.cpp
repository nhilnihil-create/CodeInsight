#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <vector>
#include <map>
#include <queue> 
#include <stack>
#include <set>
#include <list>

using namespace std;
typedef long long ll;
#define rep(i, s, e) for (int(i) = (s); (i) <= (e); ++(i))
#define all(x) x.begin(),x.end()


int main()
{
	int x, y; cin >> x >> y;
	int ans = 0;
	int a = 100000;
	if (x == 3)ans += a;
	if (x == 2)ans += a * 2;
	if (x == 1)ans += a * 3;
	if (y == 3)ans += a;
	if (y == 2)ans += a * 2;
	if (y == 1)ans += a * 3;
	if (x == 1 && y == 1)ans += a * 4;
	cout << ans << endl;
}
