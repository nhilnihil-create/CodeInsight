#include <set>
#include <cstdio>
#include <iostream>
using namespace std;

const int INF = 1 << 30;
const int dx[] = { 1, 0, -1, 0 };
const int dy[] = { 0, -1, 0, 1 };

int main()
{
	int N, M;
	while (scanf("%d", &N) != EOF) {
		if (N == 0)
			break;

		set<pair<int, int> > juel;
		for (int i = 0; i < N; ++i) {
			pair<int, int> p;
			scanf("%d %d", &p.first, &p.second);
			juel.insert(p);
		}

		scanf("%d", &M);
		int ans = 0;
		pair<int, int> s = pair<int, int>(10, 10);
		for (int i = 0; i < M; ++i) {
			pair<char, int> d;
			cin >> d.first >> d.second;
			int dir;
			switch (d.first) {
			case 'N':
				dir = 3;
				break;
			case 'E':
				dir = 0;
				break;
			case 'S':
				dir = 1;
				break;
			case 'W':
				dir = 2;
				break;
			}

			for (int j = 0; j < d.second; ++j) {
				s.first += dx[dir];
				s.second += dy[dir];

				set<pair<int, int> >::iterator it = juel.find(s);
				if (it != juel.end()) {
					++ans;
					juel.erase(it);
				}
			}
		}

		if (ans == N)
			printf("Yes\n");
		else
			printf("No\n");

	}

	return 0;
}