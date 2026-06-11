#include<algorithm>
#include<cmath>
#include<climits>
#include<cstdio>
#include<functional>
#include<iomanip>
#include<iostream>
#include<map>
#include<numeric>
#include<queue>
#include<set>
#include<string>
#include<utility>
#include<vector>

using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<vector<int>> vvi;
typedef vector<vector<ll>> vvll;
typedef vector<vector<string>> vvs;
typedef vector<vector<bool>> vvb;
const ll MOD = 1000000007;
#define rep(i,n) for(int i=0;i<n;i++)
#define repl(i,s,e) for(int i=s;i<e;i++)
#define reple(i,s,e) for(int i=s;i<=e;i++)
#define revrep(i,n) for(int i=n-1;i>=0;i--)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main()
{
	ll S;
	cin >> S;

	ll p = (ll)ceil(sqrtl((ld)S));
	ll q = S / p;
	ll r = S % p;

	if (r > 0)
	{
		r -= p;
		q++;
	}

	//x[0], y[0]を原点に固定して、
	//S = x[1] * y[2] - y[1] * x[2]
	//S = p * q + rと比較する。
	//ただし、rを0以下にする必要がある。

	vll x(3), y(3);

	x[0] = y[0] = 0;
	x[1] = p;
	y[2] = q;
	y[1] = - r;
	x[2] = 1;

	cout << x[0] << " ";
	cout << y[0] << " ";
	cout << x[1] << " ";
	cout << y[1] << " ";
	cout << x[2] << " ";
	cout << y[2] << endl;

	return 0;
}