#include <iostream>
#include <math.h>
using namespace std;

const int mxN = 11;
int grid[mxN][mxN];

int main() {
	int n, d;
	cin >> n >> d;
	for(int i = 1; i <= n; ++i)
		for(int j = 1; j <= d; ++j)
			cin >> grid[i][j];
	int answer = 0;
	for(int i = 1; i <= n; ++i) {
		for(int j = i + 1; j <= n; ++j) {
			int cur = 0;
			for(int k = 1; k <= d; ++k)
				cur += (grid[i][k] - grid[j][k]) * (grid[i][k] - grid[j][k]);
			double x = sqrt(cur);
			int temp = x;
			bool ok = (temp * temp) == cur;
			answer += ok;
		}
	}
	cout << answer;
}
