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
// to do : 1183

#include <complex>

#define X real()
#define Y imag()

const double EPS = 1e-11;

typedef double D;
typedef complex<D> P; // Point

// 共役複素数 conj(a);

// 符号
int sig(D a, D b=0) { return a < b - EPS ? -1 : (a > b + EPS ? 1 : 0); }

// 内積
D dot_product(P a, P b) { return (conj(a)*b).real(); }

// 外積
D cross_product(P a, P b) { return (conj(a)*b).imag(); }

/** Problem0021 : Parallelism **/
int main()
{
	int N; cin>>N;
	rep(i, N) {
		P a, b;
		D x1, y1, x2, y2;
		cin>>x1>>y1>>x2>>y2;
		a.X = (x2 - x1);
		a.Y = (y2 - y1);
		
		cin>>x1>>y1>>x2>>y2;
		b.X = (x2 - x1);
		b.Y = (y2 - y1);
		
		if (abs(cross_product(a, b))<EPS) {
			cout << "YES" << endl;
		} else {
			cout << "NO" << endl;
		}
	}
}