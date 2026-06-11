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

struct node { int p, l, r; };

node N[30];
vi A(30);
//==============================================

int preorderTreeWalk(int u) {
	if (u == -1) return 0;

	cout << " " << u;
	preorderTreeWalk(N[u].l);
	preorderTreeWalk(N[u].r);
}

int inorderTreeWalk(int u) {
	if (u == -1) return 0;

	inorderTreeWalk(N[u].l);
	cout << " " << u;
	inorderTreeWalk(N[u].r);
}

int postorderTreeWalk(int u) {
	if (u == -1) return 0;

	postorderTreeWalk(N[u].l);
	postorderTreeWalk(N[u].r);
	cout << " " << u;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n;
	cin >> n;

	REP(i, n) {
		N[i].p = N[i].l = N[i].r = -1;
	}

	int id, inputLeft, inputRight;
	REP(i, n) {
		cin >> id >> inputLeft >> inputRight;

		N[id].l = inputLeft;
		N[id].r = inputRight;

		if (inputLeft != -1) N[inputLeft].p = id;
		if (inputRight != -1) N[inputRight].p = id;
	}

	int root;
	REP(i, n) if (N[i].p == -1) root = i;

	cout << "Preorder" << "\n";
	preorderTreeWalk(root); cout << "\n";

	cout << "Inorder" << "\n";
	inorderTreeWalk(root); cout << "\n";

	cout << "Postorder" << "\n";
	postorderTreeWalk(root); cout << "\n";
	return 0;
}