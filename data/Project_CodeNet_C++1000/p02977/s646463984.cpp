#define _USE_MATH_DEFINES
#define _SILENCE_CXX17_C_HEADER_DEPRECATION_WARNING
#define _SILENCE_ALL_CXX17_DEPRECATION_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#include <bits/stdc++.h>
#include <nmmintrin.h>
#include <immintrin.h>
#include <mmintrin.h>

using namespace std;

#define dprint(Exp,...) if(Exp){fprintf(stderr, __VA_ARGS__);}
#define printe(...) fprintf(stderr, __VA_ARGS__);
#define PrtExp(_Exp)  cerr<< #_Exp <<" = "<< (_Exp)
#define PrtExpN(_Exp)  cerr<< #_Exp <<" = "<< (_Exp) <<"\n"

#define SINT(n) scanf("%d",&n)
#define SINT2(n,m) scanf("%d %d",&n,&m)
#define SINT3(n,m,o) scanf("%d %d %d",&n,&m,&o)
#define SINT4(n,m,o,P) scanf("%d %d %d %d",&n,&m,&o,&P)
#define SINT5(n,m,o,P,q) scanf("%d %d %d %d %d",&n,&m,&o,&P,&q)
#define SLL(n) scanf("%lld",&n)
#define SLL2(n,m) scanf("%lld %lld",&n,&m)
#define SLL3(n,m,o) scanf("%lld %lld %lld",&n,&m,&o)
#define SST(s) scanf("%s",s)
#define SCH(c) scanf("%c",&c)

#define GC() getchar()

#define PINT(n) printf("%d",(int)(n))
#define PINT2(n,m) printf("%d %d",(int)(n),(int)(m))
#define PINT3(n,m,l) printf("%d %d %d",(int)(n),(int)(m),(int)(l))
#define PLL(n) printf("%lld",(long long)(n))
#define PST(s) printf("%s",(s))
#define PCH(s) printf("%c",(s))

#define PINTN(n) printf("%d\n",(int)(n))
#define PINT2N(n,m) printf("%d %d\n",(int)(n),(int)(m))
#define PINT3N(n,m,l) printf("%d %d %d\n",(int)(n),(int)(m),(int)(l))
#define PLLN(n) printf("%lld\n",(long long)(n))
#define PSTN(s) printf("%s\n",(s))
#define PCHN(s) printf("%c\n",(s))

#define PSP() printf(" ")
#define PN() printf("\n")

#define PC(c) putchar(c)
#define CSP (' ')
#define SN ("\n")

#define rep(i,a) for(int i=0;i<a;i++)
#define reP(i,a) for(int i=0;i<=a;i++)
#define Rep(i,a) for(int i=a-1;i>=0;i--)
#define ReP(i,a) for(int i=a;i>=0;i--)

#define rEp(i,a) for(i=0;i<a;i++)
#define rEP(i,a) for(i=0;i<=a;i++)
#define REp(i,a) for(i=a-1;i>=0;i--)
#define REP(i,a) for(i=a;i>=0;i--)

#define repft(i,a,b) for(int i=a;i<b;i++)
#define repfT(i,a,b) for(int i=a;i<=b;i++)
#define Repft(i,a,b) for(int i=a-1;i>=b;i--)
#define RepfT(i,a,b) for(int i=a;i>=b;i--)

#define foreach(a,it) for(auto it = a.begin(); it != a.end(); ++it)

#define FILL(a,v) fill(begin(a),end(a), v)
#define FILL0(a) memset(a,0,sizeof(a))
#define FILL1(a) memset(a,-1,sizeof(a))

typedef long long ll;

typedef unsigned long long ull;
typedef pair<int, int> Pi;
typedef pair<ll, ll>   Pll;


const int INF = 1'010'000'000; // 0x3C33'6080
const ll INFLL = 0x1f1f1f1f1f1f1f1fLL;//2,242,545,357,980,376,863

template <class A, class B> inline ostream& operator<<(ostream& st, const pair<A, B>& P) { return st << "(" << P.first << "," << P.second << ")"; };
template <class A, class B> inline pair<A, B> operator+(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first + Q.first, P.second + Q.second); };
template <class A, class B> inline pair<A, B> operator-(const pair<A, B>& P, const pair<A, B>& Q) { return pair<A, B>(P.first - Q.first, P.second - Q.second); };

#define fs  first
#define sc  second

/*
int n;
int n2;
int pa[16];

int d[16][16];


void dfs(int i) {
	if (i == n2) {
		test();
		return;
	}
	//for (int j = 0; j < i; ++j) {
	for (int j = i-1; j >= 0; --j) {
		pa[i] = j;
		dfs(i + 1);
	}
}

void make(int N) {
	n = N;
	n2 = N * 2;
	pa[0] = -1;
	pa[1] = 0;
	dfs(2);
}

int main() {
	make(6);
	cout << "FIN" << endl;
}
*/

vector<Pi> solve(const int n) {
	int n2 = n * 2;
	if (n == (n&(-n))) {
		return {};
	}
	int x = 0;
	reP(i, n) {
		x ^= i;
		// printf("%2d : %2d (%2x)\n", i, x, x);
	}
	vector<Pi> ret;

	if (x == 0) {
		repft(i, 1, n2) {
			ret.emplace_back(i, i+1);
		}
		return ret;
	}
	if (x == 1) {
		repft(i, 2, n) {
			ret.emplace_back(i, i + 1);
		}
		ret.emplace_back(n, n + 2);
		repft(i, 2, n) {
			ret.emplace_back(i + n, i + n + 1);
		}
		ret.emplace_back(1, 2);
		ret.emplace_back(3, n + 1);
		return ret;
	}
	if (x == n) {
		vector<int> v;
		int a = (n&(-n));
		int b = a ^ n;
		v.push_back(a);
		v.push_back(b);
		repfT(i, 1, n) {
			if (a == i || b == i || i == n) continue;
			v.emplace_back(i);
		}
		rep(i, v.size() - 1) ret.emplace_back(v[i], v[i + 1]);
		rep(i, v.size() - 1) ret.emplace_back(v[i]+n, v[i + 1]+n);
		ret.emplace_back(v.back(), v.front() + n);
		ret.emplace_back(a, n);
		ret.emplace_back(b, n*2);
		return ret;
	}
	if (x == n + 1) {
		int a, b;
		rep(i, n) {
			a = 1 << i;
			b = x - a;
			if (a > b) break;
		}
		int x, y, z;
		for (x = 1; x <= n; ++x) {
			y = a ^ x;
			z = b ^ x;
			if (y >= n) continue;
			if (z >= n) continue;
			if (x != y && y != z && z != x) break;
		}
		vector<int> v;
		v.push_back(y);
		v.push_back(x);
		v.push_back(z);
		/*
		PrtExpN(x);
		PrtExpN(y);
		PrtExpN(z);
		PrtExpN(a);
		PrtExpN(b);
		*/
		repfT(i, 1, n) {
			if (i == a || i == b || i == x || i == y || i == z) continue;
			v.emplace_back(i);
		}
		rep(i, v.size() - 1) ret.emplace_back(v[i], v[i + 1]);
		rep(i, v.size() - 1) ret.emplace_back(v[i] + n, v[i + 1] + n);
		ret.emplace_back(v.back(), v.front() + n);
		ret.emplace_back(a, y);
		ret.emplace_back(b, x);
		ret.emplace_back(x, a + n);
		ret.emplace_back(z, b + n);
		return ret;

		/*
		rep(i, v.size() - 1) cout << v[i] << " " << v[i + 1] << endl;
		rep(i, v.size() - 1) cout << v[i] + n << " " << v[i + 1] + n << endl;
		cout << v.back() << " " << v.front() + n << endl;
		cout << a << " " << y << endl;
		cout << b << " " << x << endl;
		cout << x << " " << a + n << endl;
		cout << z << " " << b + n << endl;
		*/
	}

}


int d[4096][4096];

int main() {
	/*
	{
		int x = 0;
		rep(i, 50) {
			x ^= i;
			printf("%2d : %2d (%2x)\n", i, x, x);
		}
	}
	100000;
	*/


	int n;
	while (cin >> n) {
	//for(int n = 1; n < 2048; ++n){
		auto ret = solve(n);
		if (ret.size() == 0) {
			cout << "No" << endl;
		} else {
			cout << "Yes" << endl;
			for (const auto&p : ret) {
				cout << p.first << " " << p.second << endl;
			}
			/*
			{
				const int n2 = n * 2;
				rep(i, n2) rep(j, n2) d[i][j] = -1;
				rep(i, n2) {
					d[i][i] = 0;
				}
				for (const auto&p : ret) {
					int i = p.first - 1;
					int j = p.second - 1;
					d[i][j] = d[j][i] = (i%n + 1) ^ (j%n + 1);
				}
				rep(k, n2) rep(i, n2) rep(j, n2) {
					if (d[i][j] != -1) continue;
					if (d[i][k] == -1) continue;
					if (d[k][j] == -1) continue;
					d[i][j] = d[i][k] ^ d[k][j] ^ (k%n + 1);
				}
				bool ok = true;
				rep(i, n) {
					if (d[i][i + n] != i + 1) ok = false;
				}
				if (ret.size() != n2-1 || !ok) {
					cerr << "ERRRE!" << endl;
					assert(false);
				}
			}
			*/
		}
	}

}


/*
1 NG
2 NG
3
4 NG
5
b2 a1
c3 b2
d4 c3
e5 d4
f1 c3
g2 e5
h3 g2
i4 h3
j5 i4

*/