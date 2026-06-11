#include "bits/stdc++.h"
using namespace std;


class friends {
private:
	int n, m;

	int ans = 1;
	int depth = 0;

	vector<set<int>> adjacencyList;
	vector<bool> seeked;

public:
	friends(int _n, int _m) {
		n = _n;
		m = _m;

		adjacencyList.resize(n + 1);
		seeked.resize(n + 1);
		for (auto e : seeked) e = false;
	}

	void setAdjList(int a, int b);
	void search(int i = 1);
	void show();
	void solve();
};

void friends::setAdjList(int a, int b) {
	adjacencyList[a].insert(b);
	adjacencyList[b].insert(a);
}

void friends::search(int i) {
	for (auto e : adjacencyList[i]) {
		if (seeked[e] == true) continue;

		depth += 1;
		seeked[e] = true;
		search(e);
	}
}

void friends::show() {
	for (int i = 1; i <= n; i++) {
		cout << i << ":";
		for (auto e : adjacencyList[i]) {
			cout << " " << e;
		}
		cout << endl;
	}

	for (int i = 1; i <= n; i++) {
		if (seeked[i] == false) cout << "未探索" << endl;;
	}
}

void friends::solve() {
	search();
	ans = max(ans, depth);

	for (int i = 1; i <= n; i++) {
		if (seeked[i] == true) continue;

		depth = 0;
		search(i);

		ans = max(ans, depth);
	}

	cout << ans << endl;

	//show();
}

int main() {
	int n, m;
	cin >> n >> m;

	friends friends(n, m);

	int a, b;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		friends.setAdjList(a, b);
	}

	friends.solve();
}