#include <cmath>
#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<queue>
#include<set>
#include<map>
#include<bitset>
#include<iomanip>
#include<stack>
#include<set>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> P;
ll mod = 1000000007;
char c[15][15];
char d[15][15];
int main() {
	int h, w, k;
	cin >> h >> w >> k;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> c[i][j];
		}
	}
	ll count = 0;

	for (int x = 0; x < (1 << h); x++) {
		for (int y = 0; y < (1 << w); y++) {
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					d[i][j] = c[i][j];
				}
			}
			for (int i = 0; i < h; i++) {
				if (x & (1 << i)) {
					for (int j = 0; j < w; j++) {
						d[i][j] = 'R';
					}
				}
			}
			for (int i = 0; i < w; i++) {
				if (y & (1 << i)) {
					for (int j = 0; j < h; j++) {
						d[j][i] = 'R';
					}
				}
			}
			ll kcount = 0;
			for (int i = 0; i < h; i++) {
				for (int j = 0; j < w; j++) {
					if (d[i][j] == '#') {
						kcount++;
					}
				}
			}
			if (kcount == k) {
				count++;
			}
			kcount = 0;
		}
	}
	cout << count << endl;
}