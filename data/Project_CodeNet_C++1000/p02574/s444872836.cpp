#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define endl "\n"
#define pb push_back
#define mp make_pair
#define int long long
#define mod 1000000007
#define DEBUG cout<<"Hello1\n";
#define all(v) (v).begin(),(v).end()
#define clr(x) memset(x,0,sizeof(x))
#define deb(...) debug(#__VA_ARGS__, __VA_ARGS__);
const int N = 1e6 + 5;
const double pi =  acosl(-1);
const long long inf = 1e18 + 5;
using namespace std;
template<typename T> void debug(string s, T x)
{
	cout << s << " = " << x << "\n";
}
template<typename T, typename... Args> void debug(string s, T x, Args... args)
{
	cout << s.substr(0, s.find(',')) << " = " << x << " | ";
	debug(s.substr(s.find(',') + 2), args...);
}
template<class T> void print_container(T &container)
{
	for (auto &t : container)
	{
		cout << t << " ";
	}
	cout << endl;
}
template<class T> void print_pair_container(T &container)
{
	for (auto &t : container)
	{
		cout << t.first << " " << t.second << endl;
	}
	cout << endl;
}
template<class T> void printArr(T &a, int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << a[i] << " ";
	}
	cout << endl;
}
typedef long long ll;
typedef pair<int, int> pii;

//Template Ends
int n;
int a[N];

set<int> ms;


int spf[N];
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i < N; i++)
		spf[i] = i;

	for (int i = 4; i < N; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i < N; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j < N; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

// A O(log n) function returning primefactorization
// by dividing by smallest prime factor at every step
bool getFactorization(int x)
{
	set<int> factors;
	while (x != 1)
	{
		factors.insert(spf[x]);
		x = x / spf[x];
	}
	for (int x : factors) {
		if (ms.count(x)) {
			return 1;
		} else {
			ms.insert(x);
		}
	}
	return 0;
}

void solve()
{
	ll prod = 1, l = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sieve();

	bool common_found = false;
	for (int i = 0; i < n; i++) {
		if (getFactorization(a[i])) {
			common_found = 1;
			break;
		}
	}

	if (!common_found) {
		cout << "pairwise coprime";
	} else {
		ll g = a[0];
		for (int i = 0; i < n; i++) {
			g = __gcd(g, a[i]);
		}
		if (g == 1) {
			cout << "setwise coprime";
		} else {
			cout << "not coprime";
		}
	}


}

int32_t main()
{
	IOS;

	solve();

	return 0;
}


