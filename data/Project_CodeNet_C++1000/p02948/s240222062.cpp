#include<iostream>
#include<queue>
using namespace std;
int a[100000];
int b[100000];
queue<int> que2[100001];
int main() {
	priority_queue<int> que;

	int n, m;
	cin >> n >> m;

	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i] >> b[i];
		que2[a[i]].push(b[i]);
	}
	int j;
	int counter = 0;
	for (i = 1; i <= m; i++) {
		while (que2[i].size()) {
			que.push(que2[i].front()); que2[i].pop();
		}
		if (que.size() > 0) {
			//cout << que.top();
			counter = counter + que.top(); que.pop();
		}//cout << 'a';
	}
	cout << counter << endl;
	return 0;

}