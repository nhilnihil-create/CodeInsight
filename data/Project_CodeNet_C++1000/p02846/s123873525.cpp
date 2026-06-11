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
	ll x = (a1 - b1)*t1, y = (a2 - b2)*t2;
	ll dif = abs(x+y);
	if (dif == 0)cout << "infinity" << endl;
	else if ((x < 0 &&x + y < 0) || (0<x && 0<x + y))cout << 0 << endl;
	else
	{
		ll z = abs(x / dif);
		if (x%dif == 0)cout << 2 * z << endl;
		else cout << 2*z + 1 << endl;
	}
}
