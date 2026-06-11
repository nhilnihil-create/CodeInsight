#define _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"
#include <string>
using namespace std;

//宣言
typedef long long ll;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;

//数値
#define MOD 1000000007
#define INF (1<<20)
const double EPS = 1e-10;
const double PI = acos(-1.0);

//操作
#define FOR(i,a,b) for(int i=a;i<b;++i)
#define REP(i,n) FOR(i,0,n)
#define REPB(i,n) for(int i=n;i>=0;--i)
#define SORT(A) sort(A,A+sizeof(A)/sizeof(A[0]))
#define VSORT(A) sort(A.begin(),A.end())
#define EXIST(s,e) (s.find(e)!=s.end())
#define PB push_back
#define MP make_pair
#define Int(x) int x; scanf("%lld", &x);
#define int2(x, y) int x, y; scanf("%lld %lld", &x, &y);

//DEBUG
//debug
#define dump(x)  cerr << #x << " = " << (x) << endl;
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;



int main() {
	int e=1;
	do {
		scanf("%d", &e);
		if (e == 0) break;
		int x=0, y=0, z=e;
		int m = x + y + z;
		for (z = 100;z >= 0;z--) {
			for (y = 1000;y >= 0;y--) {
				x = e - z*z*z - y*y;
				if (x >= 0 && x + y + z < m) m = x + y + z;
			}
		}
		cout << m << endl;
	} while (e != 0);

}

