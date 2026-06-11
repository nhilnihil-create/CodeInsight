#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include<list>
#include <cstring>
#include <functional>
#include<unordered_map>
#include<unordered_set>
#include<bitset>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF ((Int)1<<60)
#define EPS (1e-10)
#define REP(i,n) for(int i=0; i<(int)(n); ++i)
#define RREP(i,n) for(int i=1; i<=(int)(n); ++i)
#define FOR(i,k,n) for(int i=(k);i<(int)(n);++i)
typedef long long Int;
typedef pair<Int, Int> PI;
typedef pair<int, int> P;
typedef vector<double> vec;
typedef vector<vec> mat;
const int N = 100005;
//////////////////////////////

class MaxMinQueue {
public:
	MaxMinQueue() {}
	bool empty() { return elements.empty(); }
	int size() { return elements.size(); }
	void push(int val) {
		elements.push(val);
		while (!maxElements.empty() && val > maxElements.back()) maxElements.pop_back();
		maxElements.push_back(val);
		while (!minElements.empty() && val < minElements.back()) minElements.pop_back();
		minElements.push_back(val);
	}
	int pop() {
		int val = elements.front();
		elements.pop();
		if (val == maxElements.front()) maxElements.pop_front();
		if (val == minElements.front()) minElements.pop_front();
		return val;
	}
	int peekMax() {
		return maxElements.front();
	}
	int peekMin() {
		return minElements.front();
	}
private:
	queue<int> elements;
	deque<int> maxElements;
	deque<int> minElements;
};

int n, m;
string s;
int dp[N];

void solve()
{
	cin >> n >> m;
	cin >> s;
	MaxMinQueue MinQ;
	MinQ.push(0);
	dp[n] = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (s[i] == '1') dp[i] = INF;
		else dp[i] = min(INF, MinQ.peekMin() + 1);
		MinQ.push(dp[i]);
		if (MinQ.size() > m) MinQ.pop();
	}

	if (dp[0] == INF) {
		cout << "-1" << endl;
		return;
	}

	int cur = dp[0] - 1;
	int last = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i] == cur) {
			cout << (i - last) << " ";
			cur--;
			last = i;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
