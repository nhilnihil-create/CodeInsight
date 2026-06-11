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
	ll t1, t2, a1, a2, b1, b2;
	cin >> t1 >> t2 >> a1 >> a2 >> b1 >> b2;
	if (((a1-b1)*t1 + (a2-b2)*t2>0 && (a1 - b1)*t1>0) || ((a1 - b1)*t1 + (a2 - b2)*t2 < 0 && (a1 - b1)*t1 < 0))cout << 0 << endl;
	else if ((t1*a1 + t2 * a2) == (t1 * b1 + t2 * b2))cout << "infinity" << endl;
	else
	{
		ll dif = abs((t1*a1 + t2 * a2) - (t1 * b1 + t2 * b2));
		ll tmp = abs(b1*t1 - a1 * t1);
		ll ans = (tmp / dif) * 2;
		if (tmp%dif != 0)++ans;
		cout << ans << endl;
	}
}
