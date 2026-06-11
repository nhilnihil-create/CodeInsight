#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
typedef pair<LL, LL> pLL;

int blackcount(int N, int W, char tbl[][6],int p, int q)
{
	int count = 0;
	for (int i = 0; i < N; i++) {
		if ((p >> i) % 2 == 0) {
			for (int j = 0; j < W; j++) {
				if ((q >> j) % 2 == 0) {
					if (tbl[i][j] == '#') {
						count++;
					}
				}
			}
		}
	}
	return count;
}

int main(void)
{
	int N, W, K, ans = 0;
	cin >> N >> W >> K;
	char tbl[6][6];
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < W; j++) {
			cin >> tbl[i][j];
		}
	}
	for (int i = 0; i < 1 << N; i++) {
		for (int j = 0; j < 1 << W; j++) {
			if (K == blackcount(N, W, tbl, i, j))
			{
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;

}