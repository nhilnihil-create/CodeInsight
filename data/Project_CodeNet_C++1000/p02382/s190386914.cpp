#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
#include <iomanip>
#include <math.h>
#include <string>
#include <queue>
#include <map>
#include <set>
#include <functional>

using namespace std;

typedef long long int ll;
typedef std::pair<int, int> pii;
typedef std::pair<ll, int> pli;
typedef std::pair<ll, ll> pll;

#define FOR(i,n,m) for(ll i=(ll)(m);i<(ll)(n);++i)
#define REP(i,n) FOR(i,n,0)
#define IREP(i,n) for(ll i=(ll)(n);i>=0;--i)
#define OF64 std::setprecision(10)

const ll MOD = 1000000007;
const ll INF = (ll)1e15;

int x[105], y[105];

int main()
{
	int N;
	cin >> N;
	REP(i, N)
	{
		cin >> x[i];
	}
	REP(i, N)
	{
		cin >> y[i];
	}

	double d = 0;
	REP(i, N)
	{
		d += abs(x[i] - y[i]);
	}
	cout << OF64 << d << endl;
	d = 0;
	REP(i, N)
	{
		d += pow(x[i] - y[i], 2);
	}
	cout << OF64 << sqrt(d) << endl;

	d = 0;
	REP(i, N)
	{
		d += pow(abs(x[i] - y[i]), 3);
	}
	cout << OF64 << cbrt(d) << endl;

	d = 0;
	REP(i, N)
	{
		d = std::max((double)abs(x[i] - y[i]), d);
	}
	cout << OF64 << d << endl;
	return 0;
}
