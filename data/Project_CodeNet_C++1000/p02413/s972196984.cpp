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

int m[105][105];
int s[105] = { 0 };

int main()
{
	int r, c;
	cin >> r >> c;
	REP(i, r)
	{
		int sum = 0;
		REP(j, c)
		{
			cin >> m[i][j];
			sum += m[i][j];
			s[j] += m[i][j];
			cout << m[i][j] << " ";
		}
		cout << sum << endl;
	}
	int sum = 0;
	REP(i, c)
	{
		cout << s[i] << " ";
		sum += s[i];
	}
	cout << sum << endl;
	return 0;
}
