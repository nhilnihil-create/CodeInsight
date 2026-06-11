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

int main()
{
	string W;
	cin >> W;
	int a = 0;
	while (true)
	{
		string s;
		cin >> s;
		if (s == "END_OF_TEXT")break;
		REP(i, s.length())
		{
			s[i] = tolower(s[i]);
		}
		if (s == W)a++;
	}
	cout << a << endl;
	return 0;
}
