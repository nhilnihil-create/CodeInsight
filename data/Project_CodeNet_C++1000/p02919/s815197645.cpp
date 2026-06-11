#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <cmath>

using namespace std;
#define PI 3.1415926535897932384626433832795
#define MOD (1000000007)
#define EPS (1e-15)
#define rep(i, n) for (int i = 0; i < (n); i++)
#define repc(i, s, n) for (int i = (s); i <= (n); i++)
#define rrep(i, n) for (int i = (n) - 1; i >= 0; i--)
#define rrepc(i, s, n) for (int i = (s); i >= (n); i--)
#define bet(x, a, b) (a) <= (x) && (x) < (b)
typedef long long ll;
typedef unsigned long long ull;

#define p(a, b) make_pair(a, b)
typedef pair<ll, int> pli;

ll P[100001];
ll L[2][100002];
ll R[2][100002];


int main()
{
	int N;
	ll ans = 0;
	priority_queue<pli, vector<pli>, greater<pli> > pq;
	queue<pli> q;

	cin >> N;
	repc(i, 1, N) cin >> P[i];

	rep(i, 2) repc(j, 1, N) {
		L[i][j] = -1;
		R[i][j] = -1;
	}

	rep(i, 2) {
		L[i][0] = 0;
		R[i][N + 1] = (ll)N + 1;
	}

	repc(i, 1, N) {
		while (!pq.empty()) {
			pli item = pq.top();
			ll v = item.first;
			int id = item.second;

			if (v >= P[i]) break;
			pq.pop();

			if (R[0][id] == -1) {
				R[0][id] = i;
				q.push(item);
			}
			else R[1][id] = i;
		}
		pq.push(p(P[i], i));
		while (!q.empty()) {
			pq.push(q.front());
			q.pop();
		}
	}

	while (!pq.empty()) {
		int id = pq.top().second; pq.pop();
		rep(i, 2) if (R[i][id] == -1) R[i][id] = (ll)N + 1;
	}

	rrepc(i, N, 1) {
		while (!pq.empty()) {
			pli item = pq.top();
			ll v = item.first;
			int id = item.second;

			if (v >= P[i]) break;
			pq.pop();

			if (L[0][id] == -1) {
				L[0][id] = i;
				q.push(item);
			}
			else L[1][id] = i;
		}
		pq.push(p(P[i], i));
		while (!q.empty()) {
			pq.push(q.front());
			q.pop();
		}
	}

	while (!pq.empty()) {
		int id = pq.top().second; pq.pop();
		rep(i, 2) if (L[i][id] == -1) L[i][id] = 0;
	}

	repc(i, 1, N) {
		ll Lnum = (L[0][i] - L[1][i]) * (R[0][i] - i);
		ll Rnum = (i - L[0][i]) * (R[1][i] - R[0][i]);
		ans += P[i] * (Lnum + Rnum);
	}

	cout << ans << endl;

	return 0;
}
