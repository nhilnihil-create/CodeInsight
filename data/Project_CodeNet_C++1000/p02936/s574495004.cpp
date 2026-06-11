#include <iostream>
#include <map>
#include <algorithm>
#include <string>
#include <vector> 
#include <numeric>
#include <cmath>
#include <queue>
#include <iomanip>
#include <functional>


#define CHMAX(a,b) a = std::max(a,b)
#define CHMIN(a,b) a = std::min(a,b)
#define MAXMIN(a,b,c) std::max(a,min(b,c))
#define CHABS(a) a = std::abs(a) 
#define COUT(a) std::cout << a << std::endl
#define CERR(a) std::cerr << a << std::endl
#define FOR(n) for(lli i = 0; i < n; i++)

using namespace std;
using lli = long long int;
using pll = pair<lli, lli>;
using tlll = tuple<lli, lli, lli>;
using vll = vector<lli>;

lli mod197 = 1000000007LL;
lli INF = 10000000000000;

// ax + by = gcd(a,b) 最大公約数
template< typename T >
T extgcd(T a, T b, T& x, T& y) {
	T d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1;
		y = 0;
	}

	return d;
}

vll graph[200000] = {};
lli score[200000] = {};
lli answer[200000] = {};

void dfs(int i,int s) {

	s += score[i];
	answer[i] = s;

	for(int j = 0;j < graph[i].size(); j++)
		if(answer[graph[i][j]] == -1)
			dfs(graph[i][j],s);

	return;
}

int main(void) {

	lli n, q;
	cin >> n >> q;

	for (int i = 0; i < n -1; i++) {
		lli a, b;
		cin >> a >> b;
		a--; b--;
		graph[a].push_back(b);
		graph[b].push_back(a);
		answer[i] = -1;
	}
	answer[n - 1] = -1;

	for (int i = 0; i < q; i++) {
		lli p, x;
		cin >> p >> x;
		p--;
		score[p] += x;
	}

	dfs(0,0);

	for (int i = 0; i < n; i++) {
		cout << answer[i] << " ";
	}


	return 0;
}