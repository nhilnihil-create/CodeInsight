#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <functional>
#define ll long long int
using namespace std;
int h[6], w[6];

int main() {
	int H, W, K, num, ans = 0;

	cin >> H >> W >> K;
	vector<string> c(H);

	for (int i = 0; i < H; i++){
		cin >> c[i];
	}

	for (int ibit = 0; ibit < (1 << H); ibit++){
		for (int jbit = 0; jbit < (1 << W); jbit++){
			num = 0;
			for (int i = 0; i < H; i++){
				for (int j = 0; j < W; j++){
					if ((ibit >> i) & 1)
						continue;
					if ((jbit >> j) & 1)
						continue;
					if (c[i][j] == '#'){
						num++;
					}
				}
			}
			if (num == K){
				ans++;
			}
		}
	}
	cout << ans << endl;

	return 0;
}