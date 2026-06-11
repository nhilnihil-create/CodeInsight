	#include <bits/stdc++.h>
using namespace std;
 
typedef long long LL;
typedef pair<int, int> PII;
typedef vector<int> VI;
#define MP make_pair
#define PB push_back
#define X first
#define Y second
 
#define FOR(i, a, b) for(LL i = (a); i < (b); ++i)
#define RFOR(i, b, a) for(LL i = (b) - 1; i >= (a); --i)
#define ITER(it, a) for(__typeof(a.begin()) it = a.begin(); it != a.end(); ++it)
#define ALL(a) a.begin(), a.end()
#define SZ(a) (int)((a).size())
#define FILL(a, value) memset(a, value, sizeof(a))
#define debug(a) cout << #a << " = " << a << endl;

const double PI = acos(-1.0);
const LL INF = 1e9 + 47;
const int mod = 1000 * 1000 * 1000 + 7;
const LL LINF = INF * INF;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
const int MAX = 100005;
int n;
int main()
{
	ios_base::sync_with_stdio(0);
	cin >> n;
	for(int i = 0; i < 20; i++)
	{
		if(n == (1 << i))
		{
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;
	int maxStep = 0;
	for(int i = 0; i < 20; i++)
	{
		if((1 << i) - 1 <= n)
		{
			maxStep = i;
		}
	}
	int cnt = (1 << maxStep) - 1;
	
	for(int i = 2; i <= 2 * cnt; i++)
	{
		int fr = i , to = i - 1;
		if(fr > cnt)
		{
			fr -= cnt;
			fr += n;
		}
		if(to > cnt)
		{
			to -= cnt;
			to += n;
		}
		cout << fr << " " << to << endl;
	}
	for(int i = (1 << maxStep); i <= n - 1; i += 2)
	{
		int toXor = i ^ (i + 2);
		cout << i << " " << toXor << endl;
		cout << i + 1 << " " << i << endl;
		cout << i + n + 1 << " " << i + n << endl;
		cout << i + n + 1 << " " << toXor + 1 << endl;
	}
	if(n % 2 == 0)
	{
		int toXor = (n - 2) ^ n;
		cout << n << " " << n - 2 << endl;
		cout << toXor << " "  << 2 * n << endl;
	}
	//cerr << "Time elapsed: " << clock() / (double)CLOCKS_PER_SEC << endl;
	return 0;
}
