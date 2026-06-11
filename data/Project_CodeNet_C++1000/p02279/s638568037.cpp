#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>

using namespace std;

struct node {
	int p, k, d, t;
	int* c;
};

void bfs(int x, vector<node> &nd){
	queue<int> q;
	q.push(x);
	nd[x].d = 0;
	while (!q.empty()){
		int k = q.front(); q.pop();
		if (!nd[k].k) nd[k].t = 2;
		else nd[k].t = 1;
		for (int i = 0; i < nd[k].k; i++) {
			int c = nd[k].c[i];
			q.push(c);
			nd[c].d = nd[nd[c].p].d + 1;
		}
	}
	nd[x].t = 0;
}

int main() {
	int n, st = 0;
	cin >> n;
	vector<node> nd(n);
	vector<string> type(3);
	type[0] = "root";
	type[1] = "internal node";
	type[2] = "leaf";
	for (int i = 0; i < n; i++) nd[i].p = -1;
	for (int i = 0; i < n; i++) {
		int id, k, ck;
		cin >> id >> k;
		nd[id].k = k;
		if(k) nd[id].c = new int[k];
		for (int j = 0; j < k; j++) {
			cin >> ck;
			nd[ck].p = id;
			nd[id].c[j] = ck;
		}
	}
	while (nd[st].p != -1) st = nd[st].p;
	bfs(st, nd);
	for (int i = 0; i < n; i++) {
		cout << "node " << i << ": parent = " << nd[i].p << ", depth = " << nd[i].d << ", " << type[nd[i].t] << ", [";
		for (int j = 0; j < nd[i].k; j++) {
			if (j) cout << ", ";
			cout << nd[i].c[j];
		}
		cout << "]" << endl;
	}
}