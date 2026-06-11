#include<iostream>
#include<queue>
using namespace std;
void debug1();
int n, gragh[110][110] = {}, d[110] = {};
queue<int> q;

int main() {
	cin >> n;
	//input
	for (int i = 0; i < n; i++) {
		int u,k;
		cin >> u >> k;
		for (int j = 0; j < k; j++) {
			int t;
			cin >> t;
			gragh[u][t] = 1;
		}
	}
	//debug1();
	//search
	d[1] = 0;
	q.push(1);
	while (!q.empty()) {
		int cur = q.front();
		q.pop();
		//cerr << "visiting " << cur << " Distance: " << d[cur] << endl;
		for (int i = 1; i <= n; i++) {
			if (d[i] == 0 && gragh[cur][i] == 1 && i != 1) {
				d[i] = d[cur] + 1;
				q.push(i);
			}
		}
	}

	//from 0 to 1
	for (int i = 2; i <= n; i++) {
		if (d[i] == 0) d[i] = -1;
	}

	//output
	for (int i = 1; i <= n; i++) {
		cout << i << " " << d[i] << endl;
	}
	return 0;
}

void debug1() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cerr << gragh[i][j] << " " ;
		}
		cerr << endl;
	}
}