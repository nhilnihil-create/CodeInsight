#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)n;i++)
using Graph = vector<vector<int> >;
using GraphC = vector<vector<char> >;
typedef pair<int, int> P;
typedef int64_t ll;
const int MAX_N = 10000;
const int INF = 1000000000;


int main() {
	string S;
	cin >> S;
	int n = S.size();
	vector<int> a(n + 1);
	for (int i = 0; i < S.size(); i++)
	{
		if (S.at(i) == '<') {
			a[i + 1] = max(a[i + 1], a[i] + 1);
		}
	}
	for (int i = n-1; i >=0 ; i--)
	{
		if (S.at(i)=='>')
		{
			a[i] = max(a[i], a[i + 1] + 1);
		}
	}
	ll ans = 0;
	for (int i = 0; i <= n; i++)
	{
		ans += a.at(i);
	}
	cout << ans << endl;
}
