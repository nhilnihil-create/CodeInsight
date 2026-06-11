#define _USE_MATH_DEFINES
#include <algorithm>
#include <cstdio>
#include <functional>
#include <iostream>
#include <cstring>
#include <climits>
#include <cmath>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <time.h>
#include <vector>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> i_i;
typedef pair<ll, int> ll_i;
typedef pair<double, int> d_i;
typedef pair<ll, ll> ll_ll;
typedef pair<double, double> d_d;
struct edge { int u, v; ll w; };
 
int MOD = 1000000007;

int main() {
	for (;;) {
		int H, W; cin >> H >> W;
		if (H == 0 && W == 0) break;
		vector< vector<char> > a(H, vector<char>(W, '#'));
		for (int i = 1; i < H - 1; i++)
			for (int j = 1; j < W - 1; j++)
				a[i][j] = '.';
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++)
				cout << a[i][j];
			cout << endl;
		}
		cout << endl;
	}
}