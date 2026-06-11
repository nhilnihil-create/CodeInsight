#include<iostream>
#include<vector>
#include<queue>
#include<list>
using namespace std;
vector<int> v[10000];
int dep[10000];
int n,m;
void solve() {
	queue<int>q;
	for (int i = 0; i < n; i++) {
		if (v[i].empty()) {
			q.push(i);
			dep[i] = 1;
		}
	}
	while (!q.empty()) {
		int k = q.front();
		q.pop();
		cout << k << endl;
		for (int i = 0; i < n; i++) {
			if (dep[i]) continue;
			for (vector<int>::iterator it = v[i].begin(); it != v[i].end(); it++) {
				if (*it == k) {
					v[i].erase(it);
					if (v[i].empty()) {
						q.push(i);
						dep[i] = 1;
					}
					break;
				}
			}
		}
	}
}
int main(void) {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a);
	}
	solve();
}
