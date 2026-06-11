#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);	
	int h, w, k;
	long long int cnt = 0;
	cin >> h >> w >> k;
	vector <string> grid(h);
	for (auto &i : grid) cin >> i;
	for (int i = 0; i < (1 << w); ++i){
		for (int j = 0; j < (1 << h); ++j){
			long long int black = 0;
			for (int row = 0; row < h; ++row){
				if ( ((1 << row) & j ) != 0){
				for (int col = 0; col < w; ++col){
					if ( ((1 << col) & i) != 0){
						if (grid[row][col] == '#') ++black;
					}
				}
				}
			}
			if (black == k) ++cnt;
		}
	}
	cout << cnt << "\n";
	return 0;
}
