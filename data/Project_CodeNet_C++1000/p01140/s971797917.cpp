#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
	int N, M, temp;
	while (cin >> N >> M, N || M) {
		vector<int> h, w, dis;
		h.reserve(N);
		w.reserve(M);
		dis.reserve(N * (N - 1) / 2);
		h.push_back(0);
		w.push_back(0);
		for (int i = 1; i <= N; i++) {
			cin >> temp;
			h.push_back(h[i - 1] + temp);
		}
		for (int i = 1; i <= M; i++) {
			cin >> temp;
			w.push_back(w[i - 1] + temp);
		}
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j <= N; j++) {
				dis.push_back(h[j] - h[i]);
			}
		}
		sort(dis.begin(), dis.end());
		int res = 0;;
		for (int i = 0; i < M; i++) {
			for (int j = i + 1; j <= M; j++) {
				auto p = equal_range(dis.begin(), dis.end(), w[j] - w[i]);
				res += distance(p.first, p.second);
			}
		}
		cout << res << endl;
	}
	return 0;
}