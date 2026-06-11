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
	int N;
	cin >> N;

	vector<ll> A(N);
	rep(i, N) cin >> A[i];

	ll x = 0;

	rep(i, N)
	{
		x += A[i];
	}

	rep(i, N)
	{
		if (i % 2 == 1) x -= 2 * A[i];
	}


	cout << x << " ";

	rep(i, N - 1)
	{
		x = 2 * A[i] - x;

		cout << x << " ";
	}

	return 0;
}