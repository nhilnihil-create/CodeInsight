#include <bits/stdc++.h>
#include <algorithm>  
#include <unordered_set>
#define _USE_MATH_DEFINES
#include <cmath>
#define ll long long

using namespace std;

const double pi = 3.14159265358979323846;

vector<int> g[100005];

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	int N, M;

	cin >> N >> M;

	int a, b;
	queue<int> room;

	for (int i = 0; i < M; i++) {
		cin >> a >> b;
		g[a].push_back(b);
		g[b].push_back(a);
	}

	int ans[100005] = { 0 };
	ans[1] = 1;
	room.push(1);

	while (!room.empty()) {

		int curr = room.front();
		room.pop();

		for (auto b : g[curr]) {
			if (!ans[b]) {
				ans[b] = curr;
				room.push(b);
			}
		}
	}

	cout << "Yes" << endl;

	for (int i = 1; i < N; i++) {
		cout << ans[i+1] << endl;
	}






	return 0;
}