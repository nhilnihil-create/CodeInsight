#include <bits/stdc++.h>

using namespace std;

/*******  All Required define Pre-Processors and typedef Constants *******/
#define SCD(t) scanf("%d", &t)
#define SCLD(t) scanf("%ld", &t)
#define SCLLD(t) scanf("%lld", &t)
#define SCC(t) scanf("%c", &t)
#define SCS(t) scanf("%s", t)
#define SCF(t) scanf("%f", &t)
#define SCLF(t) scanf("%lf", &t)
#define MEM(a, b) memset(a, (b), sizeof(a))
#define FOR(i, j, k, in) for (int i = j; i < k; i += in)
#define RFOR(i, j, k, in) for (int i = j; i >= k; i -= in)
#define REP(i, j) FOR(i, 0, j, 1)
#define RREP(i, j) RFOR(i, j, 0, 1)
#define all(cont) cont.begin(), cont.end()
#define rall(cont) cont.end(), cont.begin()
#define FOREACH(it, l) for (auto it = l.begin(); it != l.end(); it++)
#define IN(A, B, C) assert(B <= A && A <= C)
#define MP make_pair
#define PB push_back
#define INF (int)1e9
#define EPS 1e-9
#define PI 3.1415926535897932384626433832795
#define MOD 1000000007
const double pi = acos(-1.0);
typedef pair<int, int> PII;
typedef vector<PII> VPII;
typedef vector<VPII> VVPII;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<VS> VVS;
typedef map<int, int> MII;
typedef unordered_map<int, int> UMII;
typedef set<int> SI;
typedef unordered_set<int> USI;
typedef multiset<int> MSI;
typedef unordered_multiset<int> UMSI;
typedef long long ll;
typedef unsigned long long ull;

/****** Template of some basic operations *****/
template <typename T, typename U>
inline void amin(T &x, U y)
{
	if (y < x)
		x = y;
}
template <typename T, typename U>
inline void amax(T &x, U y)
{
	if (x < y)
		x = y;
}
/**********************************************/

/******* Debugging Class Template *******/
struct dummy_struct
{
	static bool a_very_long_variable_name_that_i_wont_happen_to_use_it_again;

	static void debug(string seperator)
	{
		cerr << endl;
		a_very_long_variable_name_that_i_wont_happen_to_use_it_again = true;
	}

	template <typename T, typename... Args>
	static void debug(string seperator, T &&top, Args &&... args)
	{
		if (a_very_long_variable_name_that_i_wont_happen_to_use_it_again)
		{
			a_very_long_variable_name_that_i_wont_happen_to_use_it_again = false;
		}
		else
		{
			cerr << seperator;
		}
		cerr << top;
		debug(seperator, args...);
	}
};
bool dummy_struct::a_very_long_variable_name_that_i_wont_happen_to_use_it_again = true;
template<typename... Args>
void debug(Args&&... args)
{
	dummy_struct::debug(forward<Args>(args)...);
}


int main()
{
    int l, r, d; cin >> l >> r >> d;
    int res=0;
    for (int i = l; i <= r; ++i)
    {
        if (i % d == 0)
            ++res;
    }
    cout << res << endl;
}