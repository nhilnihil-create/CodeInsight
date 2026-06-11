#include <cmath>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <vector>
#include <map>
#include<cstdio>
#include<functional>
#include <bitset>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repr(i, n) for(int i = n; i >= 0; i--)
#define ll long long
using namespace std;
template <typename T> bool chmin(T &a, const T &b) { if (a > b) { a = b; return true; } return false; }
template <typename T> bool chmax(T &a, const T &b) { if (a < b) { a = b; return true; } return false; }
const ll INF = 1000000000000000000;
const ll MOD = 1e9 + 7;

vector<pair<long long, long long>> prime_factorize(long long N) {
	vector<pair<long long, long long> > res;
	for (long long a = 2; a * a <= N; ++a) {
		if (N % a != 0) continue;
		long long ex = 0;
		while (N % a == 0) {
			++ex;
			N /= a;
		}
		res.push_back({ a, ex });
	}
	if (N != 1) res.push_back({ N, 1 });
	return res;
}

int main()
{
	int n;
	cin >> n;
	vector<ll> al(n);
	vector<ll> cop(1000001);
	rep(j, n) {
		cin >> al[j];
		vector<pair<ll, ll>> res = prime_factorize(al[j]);
		rep(i, res.size()) {
			++cop[res[i].first];
		}
	}
	string ans = "pairwise coprime";
	rep(i, 1000000) {
		if (i <= 1) {
			continue;
		}
		if (cop[i] == n) {
			ans = "not coprime";
			break;
		}
		else if (cop[i] >= 2) {
			ans = "setwise coprime";
		}
	}
	cout << ans << endl;
	system("pause");
}


