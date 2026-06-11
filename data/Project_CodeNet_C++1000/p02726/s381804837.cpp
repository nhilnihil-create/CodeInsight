#include <bits/stdc++.h>

using namespace std;

#define PI 3.14159265358979323846264338327950L


int main(void) {
	int N, X, Y;
	map<long long, long long> ans;
	// queue<long long> que;

	cin >> N >> X >> Y;





	X--;
	Y--;

	for (long long i = 0; i < N; i++) {
		queue<long long> que;
		map<long long, bool> check;
        vector<int> dist(N,INFINITY);

		que.push(i);
		dist[i]=0;
		while (!que.empty()) {
			long long tmp;
			tmp = que.front(); que.pop();

			if (check[tmp] == true)continue;



			if (tmp + 1 < N) {
				que.push(tmp + 1);
				dist[tmp + 1] = min(dist[tmp] + 1, dist[tmp + 1]);
			}
			if (tmp - 1 >= 0) {
				que.push(tmp - 1);
				dist[tmp - 1] = min(dist[tmp] + 1, dist[tmp - 1]);
			}
			if (tmp == X) {
				que.push(Y);
				dist[Y] = min(dist[tmp] + 1, dist[Y]);
			}
			if (tmp == Y) {
				que.push(X);
				dist[X] = min(dist[tmp] + 1, dist[X]);
			}

			check[tmp] = true;


		}

        for (long long j = i + 1; j < N; j++) {
			ans[dist[j]]++;
		}
	}


	// for (long long i = 0; i < N; i++) {
	// 	for (long long j = i + 1; j < N; j++) {
	// 		ans[DIST[i][j]]++;
	// 	}
	// }

	for (long long i = 1; i <= N - 1; i++) {
		cout << ans[i] << endl;
	}


	return 0;
}

