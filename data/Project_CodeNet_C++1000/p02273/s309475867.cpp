#define _CRT_SECURE_NO_WARNINGS

#include <bits/stdc++.h>

using namespace std;
#define len(n) (int)n.length()
#define pb push_back
#define ll long long
#define make_pair mkp
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define ALL(v) (v).begin(), (v).end()
#define dbg(n) cerr << "//" << #n << ":" << n <<endl
typedef pair<ll, ll> LLARR;
#define INF 999999999
const double PI = 3.1415926535897932384626433832795;

class Point
{
	public:
	Point()
	{
		x = 0.0;
		y = 0.0;
	}
	Point(double xx, double yy)
	{
		x = xx;
		y = yy;
	}
	double x;
	double y;
};

void Koch(int n, Point st, Point ed)
{
	if (n==0)
		return;
	
	Point s;
	Point u;
	Point t;
	
	s.x = (ed.x + (2 * st.x))/3.0;
	s.y = (ed.y + (2 * st.y))/3.0;
	
	t.x = ((2 * ed.x) + st.x)/3.0;
	t.y = ((2 * ed.y) + st.y)/3.0;
	
	double rad = PI / 180 * 60;

	u.x = (t.x - s.x) * cos(rad) - (t.y - s.y) * sin(rad) + s.x;
	u.y = (t.x - s.x) * sin(rad) + (t.y - s.y) * cos(rad) + s.y;
	
	Koch(n-1, st, s);
	cout << s.x << " " << s.y << endl;
	Koch(n-1, s, u);
	cout << u.x << " " << u.y << endl;
	Koch(n-1, u, t);
	cout << t.x << " " << t.y << endl;
	Koch(n-1, t, ed);
	
}

int main()
{
	ios::sync_with_stdio(false);

	int n;
	cin >> n;
	
	Point st = Point(0.0, 0.0);
	Point ed = Point(100.0, 0.0);
	
	cout << fixed << setprecision(8);
	cout << st.x << " " << st.y << endl;
	Koch(n, st, ed);
	cout << ed.x << " " << ed.y << endl;
	
	return 0;
}