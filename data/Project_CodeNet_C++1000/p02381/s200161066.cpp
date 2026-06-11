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

int S[1005];

int main()
{
	while (true)
	{
		int N;
		cin >> N;
		if (N == 0)break;

		double sum = 0;
		REP(i, N)
		{
			cin >> S[i];
			sum += S[i];
		}
		sum /= N;

		double A = 0;
		REP(i, N)
		{
			A += pow((S[i] - sum), 2);
		}
		A /= N;
		A = sqrt(A);
		cout << OF64 << A << endl;
	}
	return 0;
}
