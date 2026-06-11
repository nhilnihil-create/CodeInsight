# include "bits/stdc++.h"
using namespace std;
using LL = long long;
using ULL = unsigned long long;
const double PI = acos(-1);
template<class T>constexpr T INF() { return ::std::numeric_limits<T>::max(); }
template<class T>constexpr T HINF() { return INF<T>() / 2; }
template <typename T_char>T_char TL(T_char cX) { return tolower(cX); };
template <typename T_char>T_char TU(T_char cX) { return toupper(cX); };
typedef pair<LL, LL> pii;
const int vy[] = { -1, -1, -1, 0, 1, 1, 1, 0 }, vx[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
const int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
int popcnt(unsigned long long n) { int cnt = 0; for (int i = 0; i < 64; i++)if ((n >> i) & 1)cnt++; return cnt; }
int d_sum(LL n) { int ret = 0; while (n > 0) { ret += n % 10; n /= 10; }return ret; }
int d_cnt(LL n) { int ret = 0; while (n > 0) { ret++; n /= 10; }return ret; }
LL gcd(LL a, LL b) { if (b == 0)return a; return gcd(b, a%b); };
LL lcm(LL a, LL b) { LL g = gcd(a, b); return a / g*b; };
# define ALL(qpqpq)           (qpqpq).begin(),(qpqpq).end()
# define UNIQUE(wpwpw)        sort(ALL((wpwpw)));(wpwpw).erase(unique(ALL((wpwpw))),(wpwpw).end())
# define LOWER(epepe)         transform(ALL((epepe)),(epepe).begin(),TL<char>)
# define UPPER(rprpr)         transform(ALL((rprpr)),(rprpr).begin(),TU<char>)
# define FOR(i,tptpt,ypypy)   for(LL i=(tptpt);i<(ypypy);i++)
# define REP(i,upupu)         FOR(i,0,upupu)
# define INIT                 std::ios::sync_with_stdio(false);std::cin.tie(0)
# pragma warning(disable:4996)

struct Point { double x, y; };

void koch(int n, Point a, Point b) {
	if (n == 0)return;

	Point s, t, u;
	double th = PI*60.0 / 180.0;

	s.x = (2.0*a.x + 1.0*b.x) / 3.0;
	s.y = (2.0*a.y + 1.0*b.y) / 3.0;
	t.x = (1.0*a.x + 2.0*b.x) / 3.0;
	t.y = (1.0*a.y + 2.0*b.y) / 3.0;
	u.x = (t.x - s.x)*cos(th) - (t.y - s.y)*sin(th) + s.x;
	u.y = (t.x - s.x)*sin(th) + (t.y - s.y)*cos(th) + s.y;

	koch(n - 1, a, s);
	cout << fixed << setprecision(13) << s.x << " " << s.y << endl;
	koch(n - 1, s, u);
	cout << fixed << setprecision(13) << u.x << " " << u.y << endl;
	koch(n - 1, u, t);
	cout << fixed << setprecision(13) << t.x << " " << t.y << endl;
	koch(n - 1, t, b);
}

int main() {
	Point a, b;
	int n;
	cin >> n;

	a.x = 0.0, a.y = 0.0;
	b.x = 100.0, b.y = 0.0;

	cout <<fixed<<setprecision(13)<< a.x << " " << a.y << endl;
	koch(n, a, b);
	cout << fixed << setprecision(13) << b.x<<" " << b.y << endl;
}
