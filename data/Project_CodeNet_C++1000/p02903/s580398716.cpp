#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int h, w, a, b;
	cin >> h >> w >> a >> b;
	vector<vector<int>>grid(h, vector<int>(w,0));
	for (int i = 0; i < b; i++) {
		for (int j = a; j < w; j++)grid.at(i).at(j) = 1;
	}
	for (int i = b; i < h; i++) {
		for (int j = 0; j < a; j++)grid.at(i).at(j) = 1;
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) cout << grid.at(i).at(j);
		cout << endl;
	}
}