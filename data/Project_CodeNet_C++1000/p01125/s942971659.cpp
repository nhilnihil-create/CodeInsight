#include <bits/stdc++.h>

#define INF (1001001001)

int dx[8] = {0, 1, 0, -1, -1, 1, 1, -1};
int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};

using namespace std;

int main()
{
	int N, M;

	while (scanf("%d", &N), N){
		int f[32][32] = {0};
		int cnt = 0;

		for (int i = 0; i < N; i++){
			int x, y;

			scanf("%d %d", &x, &y);

			f[y][x] = 1;
		}

		scanf("%d", &M);

		int nowx, nowy;
		nowx = nowy = 10;

		for (int i = 0; i < M; i++){
			char d;
			int x;

			scanf(" %c %d", &d, &x);

			while (x--){
				if (d == 'N'){
					nowy++;

					if (f[nowy][nowx] == 1){
						cnt++;
					}
				}
				if (d == 'S'){
					nowy--;

					if (f[nowy][nowx] == 1){
						cnt++;
					}
				}
				if (d == 'W'){
					nowx--;

					if (f[nowy][nowx] == 1){
						cnt++;
					}
				}
				if (d == 'E'){
					nowx++;

					if (f[nowy][nowx] == 1){
						cnt++;
					}
				}
				f[nowy][nowx] = 9;
			}
		}

		if (cnt == N){
			puts("Yes");
		}
		else {
			puts("No");
		}
	}

	return (0);
}