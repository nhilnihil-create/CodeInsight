#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e9;
const double PI = acos(-1.0);

int main(void) {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int H, W;
	while(1) {
		cin >> H >> W;
		if(H == 0 && W == 0) break;
		for(int i = 0; i < H; i++) {
			for(int j = 0; j < W; j++) {
				cout << "#";
			}
			cout << "\n";
		}
		cout << "\n";
	}
	return 0;
}