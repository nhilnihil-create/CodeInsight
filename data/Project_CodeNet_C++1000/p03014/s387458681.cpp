#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<cmath>
#include<vector>
#include<map>
#include<set>
#include<string>
#include<queue>
#include<stack>
#include <cstring>
#include <functional>
//#include<unordered_map>
//#include<unordered_set>
using namespace std;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long Int;
typedef pair<Int, Int> P; 
const int N = 1000006;
//////////////////////////////

int h, w;
char g[2222][2222];
int tate[2222][2222];
int yoko[2222][2222];

void solve()
{
	cin >> h >> w;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			cin >> g[i][j];
			if (g[i][j] == '.') {
				tate[i][j] = 1;
				yoko[i][j] = 1;
			}
		}

	for (int i = 0; i < h; i++) {
		for (int j = 1; j < w; j++) {
			if (yoko[i][j] != 0) yoko[i][j] += yoko[i][j - 1];
		}
		for (int j = w-2; j >=0 ; j--) {
			if (yoko[i][j] != 0 && yoko[i][j] < yoko[i][j + 1]) yoko[i][j] = yoko[i][j + 1];
		}
	}

	for (int j = 0; j < w; j++) {
		for (int i = 1; i < h; i++) {
			if (tate[i][j] != 0) tate[i][j] += tate[i - 1][j];
		}
		for (int i = h-2; i >= 0; i--) {
			if (tate[i][j] != 0 && tate[i][j] < tate[i+1][j]) tate[i][j] = tate[i + 1][j];
		}
	}
	int ans = 0;
	for (int i = 0; i < h; i++)
		for (int j = 0; j < w; j++) {
			if (g[i][j] == '.') {
				ans = max(ans, tate[i][j] + yoko[i][j]);
			}
		}
	cout << ans-1 << endl;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout << fixed << setprecision(13);
	solve();
	return 0;
}
