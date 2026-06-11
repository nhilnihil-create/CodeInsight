#include "bits/stdc++.h"
#include <unordered_set>

#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
#define REP2(i, x, n) for(decltype(x) i = (x); i < (n); i++)
#define REP3(i, x, n) for(decltype(x) i = (x); i <= (n); i++)
#define RREP(i, n) for (decltype(n) i = (n) - 1;i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

#define LL long long int
#define LD long double

#define INF 1000000000
#define PI 3.14159265358979323846

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// N, E, S, W
const int dx[4] = { -1, 0,  1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<LL> vll;
//==============================================
struct Point { double x, y; };

void print(Point a) {
	printf("%.8f %.8f\n", a.x, a.y);
}

void koch(int n, Point a, Point b) {
	if (n == 0) return;
	Point s, t, u;

	double th = PI * 60.0 / 180.0;

	s.x = (2.0 * a.x + 1.0 * b.x) / 3.0;
	s.y = (2.0 * a.y + 1.0 * b.y) / 3.0;

	t.x = (1.0 * a.x + 2.0 * b.x) / 3.0;
	t.y = (1.0 * a.y + 2.0 * b.y) / 3.0;

	u.x = (t.x - s.x) * cos(th) - (t.y - s.y) * sin(th) + s.x;
	u.y = (t.x - s.x) * sin(th) + (t.y - s.y) * cos(th) + s.y;

	koch(n - 1, a, s); print(s);
	koch(n - 1, s, u); print(u);
	koch(n - 1, u, t); print(t);

	koch(n - 1, t, b);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;
	Point a = { 0, 0 }, b = { 100, 0 };

	print(a);
	koch(n, a, b);
	print(b);

	return 0;
}