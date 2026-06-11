#include <bits/stdc++.h>

using namespace std;

#ifdef NeverBeRed
#include "debug.h"
#else
#define debug(...) 9715
#endif
typedef long long ll;
typedef long double ld;
typedef complex<ll> point;
#define F first
#define S second

ll cross(point a, point b) { return imag(conj(a) * b); }

int qua(point x)
{
	if (x.real() > 0 && x.imag() >= 0) return 0;
	if (x.real() <= 0 && x.imag() > 0) return 1;
	if (x.real() < 0 && x.imag() <= 0) return 2;
	return 3;
}

int main()
{
	#ifdef TurnRed
		//freopen("a.in", "r", stdin);
		//freopen("a.out", "w", stdout);
	#endif

	ios_base::sync_with_stdio(0), cin.tie(0);

	int n;
	cin >> n;
	vector<point> v;
	for (int i = 0, x, y; i < n; ++i)
	{
		cin >> x >> y;
		point p = { x, y };
		if (x != 0 || y != 0) v.push_back(p);
	}

	ll ans = 0;
	sort(v.begin(), v.end(), [](const point &x, const point &y)
	{
		int qx = qua(x);
		int qy = qua(y);
		if (qx != qy) return qx < qy;
		return cross(x, y) > 0;
	});

	n = v.size();
	for (int i = 0; i < n; ++i)
	{
		point p = { 0, 0 };
		for (int j = i, k = n; k--; j = (j+1) % n)
		{
			p += v[j];
			ans = max(ans, norm(p));
		}
	}
	cout << setprecision(20) << fixed << sqrtl(ans) << "\n";

	return 0;
}
