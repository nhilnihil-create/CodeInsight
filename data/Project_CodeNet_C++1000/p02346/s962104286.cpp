#include <stdio.h>
#include <limits.h>
#include <math.h>
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
#define BINARY(x) static_cast<bitset<16> >(x);
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define REP(i,m,n) for (int i=m;i<(int)(n);i++)
#define if_range(x, y, w, h) if (0<=(int)(x) && (int)(x)<(int)(w) && 0<=(int)(y) && (int)(y)<(int)(h))

const int INF = 100000000;
typedef double D;
const double EPS = 1e-8;
const double PI = 3.14159;
int dx[4]={-1, 0, 1, 0}, dy[4]={0, -1, 0, 1};
using namespace std;
typedef pair<int, int> P;

/** DSL_2 - B : RangeQuery - Range Sum Query **/
const int MAX_N = 1<<17;
class RSQ {
public:
	int n, dat[2*MAX_N-1];
	
	void init(int n_) {
		n=1;
		while (n<n_) n*=2;
		for (int i=0; i<2*n-1; i++) dat[i]=0;
	}
	
	RSQ() {}
	
	void add(int k, int a) {
		k += n-1;
		dat[k] += a;
		while (k>0) {
			k = (k-1)/2;
			dat[k] += a;
		}
	}
	
	int query(int a, int b, int k, int l, int r) {
		if (r<=a || b<=l) return 0;
		
		if (a<=l && r<=b) {
			return dat[k];
		} else {
			int vl = query(a, b, k*2+1, l, (l+r)/2);
			int vr = query(a, b, k*2+2, (l+r)/2, r);
			
			return vl + vr;
		}
	}
};

int main()
{
	int N, Q;
	cin>>N>>Q;
	RSQ ST;
	ST.init(N);
	
	rep(i, Q) {
		int c, x, y;
		cin>>c>>x>>y;
		if (c) {
			cout << ST.query(x-1, y, 0, 0, ST.n) << endl;
		} else {
			ST.add(x-1, y);
		}
	}
}