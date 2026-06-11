#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<vector>
#include<functional>
#include<algorithm>
#include<stdlib.h>
#include<string>
#include<string.h>
#define _USE_MATH_DEFINES
#include<math.h>
#include<deque>
#include<set>
#include<map>
#include<queue>
#include<list>
#include<iostream>
using namespace std;
typedef long long ll;
#define rep(i,a,b) for(auto i=a;i<b;i++)
#define all(_x) _x.begin(), _x.end()
#define r_sort(_x) sort(_x.begin(), _x.end(), std::greater<int>())
#define vec_cnt(_a, _n) (upper_bound(all(_a), _n) - lower_bound(all(_a), _n))
ll gcd(ll a, ll b) { return a % b == 0 ? b : gcd(b, a % b); }
//ll lcm(ll a, ll b) { return (a / gcd(a, b)) * b; }
#define INF 1 << 30
const int mod = 1000000007;
int N;
vector<string> ans;
void dfs(string s, int n) {
	if (s.size() == N) {
		ans.push_back(s);
	}
	else {
		rep(i, 0, n + 1) {
			string next = s;
			next += ('a' + i);
			dfs(next, max(i + 1, n));
		}
	}
}
int main() {
	cin >> N;
	dfs("", 0);
	for (auto st : ans) {
		puts(st.c_str());
	}
	return 0;
}
