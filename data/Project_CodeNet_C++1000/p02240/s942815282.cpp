// Ref : https://book.mynavi.jp/ec/products/detail/id=35408

#include <iostream>
#include <vector>
#include <stack>

using namespace std;
static const int NMAX = 100000;
static const int NIL = -1;

int n, group[NMAX];
vector<int> G[NMAX];

void depthFirstSearch(int ix, int id) {
	int y;
	stack<int> S;
	S.push(ix);
	while (!S.empty()) {
		ix = S.top(); S.pop();
		for (unsigned int j = 0; j < G[ix].size(); j++) {
			y = G[ix][j];
			if (group[y] == NIL) {
				group[y] = id;
				S.push(y);
			}
		}
	}
}

void classifyID() {
	int id = 0;
	for (int i = 0; i < n; i++) {
		if (group[i] == NIL) {
			depthFirstSearch(i, id);
			id++;
		}
	}
}

int main(void) {
	int m, x, y;

	cin >> n >> m;
	for (int i = 0; i < n; i++) group[i] = NIL; // initialize group list
	for (int i = 0; i < m; i++) { // create graph in linked list representation
		cin >> x >> y;
		G[x].push_back(y);
		G[y].push_back(x);
	}

	classifyID();

	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		if ((group[x] != NIL) && (group[y] != NIL) && (group[x] == group[y]))
			cout << "yes";
		else
			cout << "no";
		cout << endl;
	}

	return 0;
}
