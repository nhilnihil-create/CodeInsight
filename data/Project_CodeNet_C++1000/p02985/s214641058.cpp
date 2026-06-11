#include<iostream>
#include<math.h>
#include<algorithm>
#include<stdint.h>
#include<vector>
#include<deque>
#include<stack>
#include<string>
#include<cstring>
#include<time.h>
#include<iomanip>
#include<list>
#include<set>
#include<unordered_map>
#include<unordered_set>
#include<random>
#include<bitset>
#include <queue>
#include <map>


using namespace std;
using ll = long long;
using ull = unsigned long long;
using uint = unsigned int;
using ldouble = long double;


#define repi(i,a,b) for(ll i = (a); i < (b); i++)
#define rep(i, n) for(ll i = 0; i < (n); ++i)


struct Node {
	int par;
	vector<int> link;
};

vector<Node> nod;

ll MOD = 1e9 + 7;

ll P(ll a, ll b) {
	ll res = 1;
	for (ll x = 0; x < b; ++x) {
		res *= a - x;
		res %= MOD;
	}
	return res;
}

int main() {
	int N, K;
	cin >> N >> K;
	nod.resize(N);
	rep(i, N) nod[i].par = -1;
	rep(i, N-1) {
		int a, b;
		cin >> a >> b;
		a--; b--;
		nod[a].link.push_back(b);
		nod[b].link.push_back(a);
	}
	ll res = 1;
	res *= K;
	res *= P(K - 1, nod[0].link.size());
	res %= MOD;
	queue<int> q;
	for (int i : nod[0].link) {
		nod[i].par = 0;
		q.push(i);
	}
	while (!q.empty()) {
		int idx = q.front(); 
		q.pop();
		res *= P(K - 2, nod[idx].link.size() - 1);
		res %= MOD;
		for (int i : nod[idx].link) {
			if (i == nod[idx].par) continue;
			nod[i].par = idx;
			q.push(i);
		}
	}
	cout << res << endl;
	return 0;
}