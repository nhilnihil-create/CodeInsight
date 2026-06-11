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
	int H, W, A, B;
	cin >> H >> W >> A >> B;

	vvi c(H, vi(W, 0));

	rep(i, W - A) c[0][i] = 1;

	rep(i, W - A)
	{
		rep(j, H - B)
		{
			c[j][i] = 1;
		}
	}

	repl(i, H - B, H)
	{
		repl(j, W - A, W)
		{
			c[i][j] = 1;
		}
	}

	rep(i, H)
	{
		rep(j, W)
		{
			cout << c[i][j];
		}

		cout << endl;
	}

	return 0;
}