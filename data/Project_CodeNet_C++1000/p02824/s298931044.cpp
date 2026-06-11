#include<vector>
#include<iostream>
#include<fstream>
#include<string>
#include<cassert>
#include<algorithm>
#include<random>
#include<map>
#include<set>
 
using namespace std;
 
//int mod = 998244353;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef pair<ll, int> pli;
typedef pair<ll, ll> pll;
typedef long double ld;
typedef vector<int>vi;
typedef vector<ll>vl;
typedef vector<vector<int>>vvi;
typedef vector<vector<ll>>vvl;
typedef vector< pair<ll, ll>>vpll;
typedef vector< pair<ld, ld>>vpld;
typedef pair<ld, ld>pld;
#define mp make_pair
#define pb push_back
 
const int mod = 998244353;
int sum(int a, int b)
{
	int c = a + b;
	if (c >= mod)
	{
		c -= mod;
	}
	return c;
}
int dif(int a, int b)
{
	int c = a - b;
	if (c < 0)
	{
		c += mod;
	}
	return c;
}
int mlt(int a, int b)
{
	ll c = a * 1LL * b;
	return c % mod;
}
int ibit(int n, int i)
{
	return ((n >> i) & 1);
}
bool check(vl &vals, ll m, int v, int p, int pos)
{
	//cerr << endl;
	//cerr << pos << vals[pos]<<endl;
	if (pos < 0)
	{
		return false;
	}
	int n = vals.size();
	if (vals[pos] >= vals[n - p])
	{
	//	cerr << "Case 1" << endl;
		return true;
	}
	if (vals[pos] + m < vals[n - p])
	{
	//	cerr << "Case 2" << endl;
		return false;
	}
	vector<ll> nes;
	ll mv = (pos + p - 1);
	mv = v - mv;
	if (mv <= 0)
	{
		return true;
	}
	ll sum = 0;
	ll dif=n-v;
	for (int i = n - p; i > pos; i--)
	{
		sum += m - (vals[i]- vals[pos]);
	//	cerr << sum << ' ' << dif << ' ' << endl;
		if (sum < (n - p - i - dif + 1)*m)
		{
		//	cerr << i << endl;
			return false;
		}
	}
//	cerr << "True" << endl;
	return true;
}
void solve(istream &cin = std::cin, ostream &cout = std::cout)
{
	ll n, m, v, p;
	vl pr;
	cin >> n >> m >> v >> p;
	for (int i = 0; i < n; i++)
	{
		ll x;
		cin >> x;
		pr.push_back(x);
	}
	sort(pr.begin(), pr.end());
	int lb = -1, rb = n - 1;
	for (int turn = 0; turn < 30; turn++)
	{
		int mid = (lb + rb + turn % 2) / 2;
		if (!check(pr, m, v, p, mid))
		{
			lb = mid;
		}
		else
		{
			rb = mid;
		}
	}
	cout << n - rb<< endl;
 
}
int main()
{
	solve();
	int n;
	cin >> n;
}