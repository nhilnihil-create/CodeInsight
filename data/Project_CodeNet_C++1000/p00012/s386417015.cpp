#include <stdio.h>
#include <cctype>
#include <limits.h>
#include <math.h>
#include <complex>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <stack>
#include <queue>
#include <cstring>
#include <string>
#include <sstream>
#include <algorithm>
#include <iomanip>
#include <iostream>

#define VARIABLE(x) cerr << #x << "=" << x << endl
#define BINARY(x) static_cast<bitset<16> >(x)
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))
#define ALL(a) (a).begin(),(a).end()
const int INF = 1e9;
const double PI = 3.14159;
int dx[4]={0, 1, 0, -1}, dy[4]={-1, 0, 1, 0};
using namespace std;
typedef long long ll;
//typedef pair<int, int> P;

/* struct P {
	int x, y, n;
	P(int n, int x, int y):n(n), x(x), y(y){}
	P(){}
}; */


/** 幾何ライブラリ **/
#include <complex>

#define X real()
#define Y imag()

const double EPS = 1e-11;

typedef double D;
typedef complex<D> P; // Point

struct L { // Line
	P a, b;
	L(){}
	L(P aa, P bb) : a(aa), b(bb){}
};

// 共役複素数 conj(a);

// 符号
int sig(D a, D b=0) { return a < b - EPS ? -1 : (a > b + EPS ? 1 : 0); }

// 内積
D dot(P a, P b) { return (conj(a)*b).real(); }

// 外積
D cross(P a, P b) { return (conj(a)*b).imag(); }

// 線分abに対する点cの位置
enum STATE{LEFT=1, RIGHT=-1, BACK=2, FRONT=-2, ON=0, IN=3, OUT=-3};
int ccw(P a, P b, P c)
{
	b -= a, c -= a;
	D s = sig(cross(b, c));
	if (s) return s>0 ? LEFT : RIGHT;
	if (sig(dot(b, c))<0) return BACK;
	if (sig(abs(c), abs(b))>0) return FRONT;
	return ON;
}

// 直線lに対する点pの写像
P projection(L l, P p)
{
	return l.a + (l.b-l.a)/abs(l.b-l.a) * dot(l.b-l.a, p-l.a)/abs(l.b-l.a);
}

// 直線lに対する点pの反射
P reflection(L l, P p)
{
	return p + (projection(l, p)-p)*P(2, 0);
}

// 直線abと点cの距離
D dLP(L l, P c)
{
	return abs(cross(l.b-l.a, c-l.a))/abs(l.b-l.a);
}

// 線分abと点cの距離
D dSP(L l, P c)
{
	if (sig(dot(l.b-l.a, c-l.a))<0) return abs(c-l.a);
	if (sig(dot(l.a-l.b, c-l.b))<0) return abs(c-l.b);
	return abs(cross(l.b-l.a, c-l.a))/abs(l.b-l.a);
}

// 線分と線分の交差判定
bool iSS(L s, L t)
{
	return (ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0)
			&& (ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0);
}

// 線分と線分の距離
D dSS(L s, L t)
{
	if (iSS(s, t)) return 0;
	return min(min(dSP(t, s.a), dSP(t, s.b)), min(dSP(s, t.a), dSP(s, t.b)));
}

// 線分と線分の交点 (公差していることが前提)
P cSS(L s, L t)
{
	D d1 = dLP(t, s.a);
	D d2 = dLP(t, s.b);
	D tmp = d1 / (d1 + d2);
	return s.a + (s.b-s.a)*tmp;
}

// 直線と直線の交差判定
bool iLL(L s, L t)
{
	return sig(cross(s.b-s.a, t.b-t.a))!=0;
}

// 直線と直線の交点 iLLを確認してから使用
P cLL(L s, L t)
{
	P ss = s.b - s.a, tt = t.b - t.a;
	return s.a + ss*cross(tt, t.a-s.a)/cross(tt, ss);
}

// 多角形
typedef vector<P> G;

int containsGP(G g, P p)
{
	bool in=false;
	for (int i=0; i<g.size(); i++) {
		P a = g[i], b = g[(i+1)%g.size()];
		if (ccw(a, b, p) == ON) return ON;
		
		a -= p, b -= p;
		if (a.Y > b.Y) swap(a, b);
		if (a.Y<0 && b.Y>=0 && sig(cross(a, b))>0) in = !in;
	}
	return in?IN:OUT;
}

D area(G g)
{
	D res = 0.0;
}

/** Problem0012 : A Point In Triangle **/
int main()
{
	P a, b, c, p;
	while (cin>>a.X>>a.Y>>b.X>>b.Y>>c.X>>c.Y>>p.X>>p.Y) {
		G g;
		g.push_back(a);
		g.push_back(b);
		g.push_back(c);
		cout << (containsGP(g, p)==IN?"YES":"NO") << endl;
	}
}