#define _USE_MATH_DEFINES
#include <bits/stdc++.h>
#include <vector>
#include <iostream>
#include<algorithm>
#include<string>
#include <map>
#include <queue>
#include <stack>
#include<set>
#include<math.h>

#define DIV 1000000007
using namespace std;
using ll = long long;

int main(void) {
	int N;
	cin >> N;

	vector<queue<int>> player(N + 1);
	for (int i = 1; i <= N; i++) {
		for (int j = 0; j < N - 1; j++) {
			int a;
			cin >> a;
			player[i].push(a);
		}
	}

	ll day = 1;
	bool flag = true;
	queue<int> q;
	for (int i = 1; i <= N; i++) {
		q.push(i);
	}
	for (day = 1; flag;day++) {
		flag = false;
		vector<bool> visit(N + 1);
		int sz = q.size();
		for (int j = 0; j < sz;j++) {
			int i = q.front();
			q.pop();
			if (player[i].empty()) {
				continue;
			}
				

			int opp = player[i].front();
			if (visit[i] || visit[opp])
				continue;
			if (i == player[opp].front()) {
				player[i].pop();
				player[opp].pop();
				flag = true;
				visit[i] = true;
				visit[opp] = true;
				q.push(i);
				q.push(opp);
			}
		}
	}

	flag = true;
	for (int i = 1; i <= N; i++) {
		if (!player[i].empty()) {
			flag = false;
			break;
		}
	}
	if (flag)
		cout << day-2 << endl;
	else
		cout << -1 << endl;
}