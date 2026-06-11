#include "bits/stdc++.h"
#include <unordered_set>

#define REP(i, n) for(decltype(n) i = 0; i < (n); i++)
#define REP2(i, x, n) for(decltype(x) i = (x); i < (n); i++)
#define REP3(i, x, n) for(decltype(x) i = (x); i <= (n); i++)
#define RREP(i, n) for (decltype(n) i = (n) - 1;i >= 0; i--)

#define ALL(a) (a).begin(),(a).end()
#define SORT(c) sort((c).begin(),(c).end())
#define DESCSORT(c) sort(c.begin(), c.end(), greater<int>())

#define LL long long int
#define LD long double

#define INF 1000000000
#define PI 3.14159265358979323846

#define _CRT_SECURE_NO_WARNINGS

using namespace std;

// N, E, S, W
const int dx[4] = { -1, 0,  1,  0 };
const int dy[4] = { 0, 1,  0, -1 };

typedef pair<int, int> pii;
typedef pair<LL, LL> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<LL> vll;
//==============================================

// ??±???
vi D(100005);

struct node { int p, l, r; };
struct node N[100005];

void print(int u) {
	cout << "node " << u << ": ";
	cout << "parent = " << N[u].p << ", ";
	cout << "depth = " << D[u] << ", ";

	if (N[u].p == -1) cout << "root, ";		 // ???
	else if (N[u].l == -1) cout << "leaf, "; // ???
	else cout << "internal node, ";			 // ?????¨??????

	cout << "[";

	// ????????????????????¨???
	for (int i = 0, c = N[u].l; c != -1; i++, c = N[c].r) {
		if (i) cout << ", ";
		cout << c;
	}

	cout << "]" << "\n";
}

// ??????????????±???????±???????
int rec(int u, int p) {
	D[u] = p;
	if (N[u].r != -1) rec(N[u].r, p);		 // ???????????????????????±???????¨????
	if (N[u].l != -1) rec(N[u].l, p + 1);	 // ?????????????????????????????±???+1????¨????
	return 0;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	REP(i, n) N[i].p = N[i].l = N[i].r = -1;

	int id, k, nextId, broId;
	REP(i, n) {
		cin >> id >> k;
		REP(j, k) {
			cin >> nextId;
			if (j == 0) {
				N[id].l = nextId;
			} else {
				N[broId].r = nextId;
			}
			broId = nextId;
			N[nextId].p = id;
		}
	}

	int r;

	//????????????????±???????
	REP(i, n) {
		if (N[i].p == -1) r = i;
	}

	// ??±???????±???????
	rec(r, 0);

	// ??????
	REP(i, n) print(i);
	return 0;
}