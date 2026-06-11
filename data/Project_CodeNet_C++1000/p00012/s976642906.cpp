#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>
#include <functional>
#include <numeric>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <utility>
#include <sstream>
#include <complex>

using namespace std;

#define FOR(i,a,b) for(long long i=(a);i<(b);i++)
#define REP(i,N) for(long long i=0;i<(N);i++)
#define ALL(s) (s).begin(),(s).end()
#define fi first
#define se second

#define PI acos(-1.0)
#define INF 1000000007
#define EPS 1e-10
#define MAX_N 20000
#define MAX_M 16

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

double dx1, dy1, dx2, dy2, dx3, dy3, px, py;

int main(){
	while (cin >> dx1 >> dy1 >> dx2 >> dy2 >> dx3 >> dy3 >> px >> py){
		double s = fabs((dx2 - dx1)*(dy3 - dy1) - (dx3 - dx1)*(dy2 - dy1)) / 2.0;
		double s1 = fabs((dx1 - px)*(dy2 - py) - (dx2 - px)*(dy1 - py)) / 2.0;
		double s2 = fabs((dx2 - px)*(dy3 - py) - (dx3 - px)*(dy2 - py)) / 2.0;
		double s3 = fabs((dx3 - px)*(dy1 - py) - (dx1 - px)*(dy3 - py)) / 2.0;

		if (fabs(s - (s1 + s2 + s3)) <= EPS){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
		}
	}
}