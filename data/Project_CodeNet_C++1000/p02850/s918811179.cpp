#include <bit>
#include <bitset>
#include <assert.h>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <sstream>
#include <iostream>
#include <set>
#include <map>
#include <vector>
#include <math.h>
#include <stdlib.h>
#include <queue>
#include <stack>


typedef long double ld;
typedef long long ll;

using namespace std;

#define MAXN (1 << 20)

vector<int> a[MAXN];
int n;
vector<pair<int, int> > edges;
map<pair<int, int>, int> colors;
int deg;
int v[MAXN];

void dfs(int cur, int prevc) {
	//cerr << cur << " " << prevc << endl;
	v[cur] = 1;
	int color = 0;
	for (int i = 0; i < a[cur].size(); i++) {
		int nnext = a[cur][i];
		if (!v[nnext]) {
			if (color == prevc) {
				color++;
			}
			pair<int, int> e = make_pair(cur, nnext);
			if (e.first > e.second) {
				swap(e.first, e.second);
			}
			colors[e] = color;
			dfs(nnext, color);
			color++;
		}
	}
}


int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int v1, v2;
		cin >> v1 >> v2;
		if (v1 > v2) {
			swap(v1, v2);
		}
		v1--;
		v2--;
		a[v1].push_back(v2);
		a[v2].push_back(v1);
		edges.push_back(make_pair(v1, v2));
	}
	deg = 0;
	for (int i = 0; i < n; i++) {
		deg = max(deg, (int)a[i].size());
	}
	dfs(0, -1);
	cout << deg << endl;
	for (int i = 0; i < edges.size(); i++) {
		cout << colors[edges[i]] + 1 << endl;
	}
	return 0;
}
