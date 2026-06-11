#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<cmath>
#include<ctime>
#include<cctype>
#include<climits>
#include<iostream>
#include<string>
#include<vector>
#include<map>
#include<list>
#include<queue>
#include<deque>
#include<algorithm>
#include<numeric>
#include<utility>
#include<complex>
#include<memory>
#include<functional>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
#define INF 999999999
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<long, long> pll;
typedef long long ll;

int dy[] = { 0, 0, 1, -1, 0 };
int dx[] = { 1, -1, 0, 0, 0 };


int main(){
	ios::sync_with_stdio(false);

	vd x(3), y(3);
	double px, py;
	double a1, a2, a3;
	bool s = false;

	while (cin >> x[0] >> y[0] >> x[1] >> y[1] >> x[2] >> y[2] >> px >> py){
		s = false;

		a1 = (x[1] - x[0])*(py - y[1]) - (y[1] - y[0])*(px - x[1]);
		a2 = (x[2] - x[1])*(py - y[2]) - (y[2] - y[1])*(px - x[2]);
		a3 = (x[0] - x[2])*(py - y[0]) - (y[0] - y[2])*(px - x[0]);

		if (((a1 > 0) && (a2 > 0) && (a3 > 0)) || ((a1 < 0) && (a2 < 0) && (a3 < 0)))
			s = !s;

		if (s)
			puts("YES");
		else
			puts("NO");
	}
}