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

	vector<int> A(N + 1);
	rep(i, N) cin >> A[i + 1];

	vector<int> B(N + 1);
	vector<int> pos;

	for(int i = N; i >= 1; i--)
	{
		int s = 0;

		for (int j = 2 * i; j <= N; j += i)
		{
			s += B[j];
		}

		if (s % 2 == A[i])
		{
			B[i] = 0;
		}
		else
		{
			B[i] = 1;
			pos.push_back(i);
		}
	}


	cout << pos.size() << endl;

	for (auto x : pos) cout << x << " ";

	return 0;
}