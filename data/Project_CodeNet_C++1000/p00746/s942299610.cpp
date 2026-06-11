#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int N;
vector<pii> squares;

void solve() {
	int maxx = 0, minx = 0, maxy = 0, miny = 0;
	squares.assign(N, make_pair(0, 0));
	
	for (int i = 1; i < N; i++) {
		int n, d; cin >> n >> d;
		
		pii p = squares[n];
		
		if (d == 0) squares[i] = make_pair(p.first - 1, p.second);
		if (d == 1) squares[i] = make_pair(p.first, p.second - 1);
		if (d == 2) squares[i] = make_pair(p.first + 1, p.second);
		if (d == 3)	squares[i] = make_pair(p.first, p.second + 1);
		
		maxx = max(maxx, squares[i].first);
		minx = min(minx, squares[i].first);
		maxy = max(maxy, squares[i].second);
		miny = min(miny, squares[i].second);
	}
	
	int w = maxx - minx + 1, h = maxy - miny + 1;
	cout << w << " " << h << endl;
}

int main() {
	while (1) {
		cin >> N; if (N == 0) break;
		solve();
	}
	
	return 0;
}