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

typedef long long ll;
typedef pair<ll, ll> P;
typedef pair<double, double> PD;
typedef pair<string, ll> PS;
typedef vector<ll> V;
typedef pair<P, char> PC;

int n;
int y, m, d;

int solve(int y, int m, int d){
	int res = 0;
	res += (y - 1) / 3 * 590;
	res += (y - 1) % 3 * 195;
	if (y % 3 == 0){
		REP(i, m - 1)res += 20;
	}
	else {
		REP(i, m - 1){
			if ((i + 1) % 2 == 0)res += 19;
			else res += 20;
		}
	}
	res += d;
	return res;
}

int main(){
	cin >> n;
	REP(i, n){
		cin >> y >> m >> d;
		cout << 196471 - solve(y, m, d) << endl;
	}
}