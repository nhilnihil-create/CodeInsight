#include <iostream>
#include <fstream>
#include <utility>
#include <queue>
#include <vector>
#include <array>
#include <stack>
#include <list>
#include <map>
#include <unordered_set>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include <cstring>
#include <cmath>

using namespace std;

typedef long long ll;

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)

int mkn(int a, int b) {
	if (a > b)swap(a, b);
	return a * 1000 + b;
}

int main() {
	int n;
	//fstream fi("C:\\Users\\shinku\\Downloads\\b08.txt");
	cin >> n;
	vector<queue<int>> a(n);
	rep(i, n) {
		rep(j, n - 1) {
			int w;
			cin >> w;
			a[i].push(w - 1);
		}
	}
	int r = 0;
	unordered_set<int> p, f, g, d;
	rep(i, n)g.insert(i);
	while (true) {
		for (auto& e : g) {
			if (!a[e].empty()) d.insert(e);
		}
		if (d.empty()) {
			bool ok = f.empty();
			if (ok) break;
			else {
				r = -1;
				break;
			}
		}
		r++;
		while (!d.empty()) {
			int t = *d.begin(); d.erase(t);
			int s = a[t].front(); a[t].pop();
			if (p.find(mkn(s, t)) == p.end()) {
				f.insert(t);
				g.erase(t);
				p.insert(mkn(s, t));
			}
			else {
				f.erase(s);
				g.insert(s);
				p.erase(mkn(s, t));
			}
		}
	}
	cout << r << endl;
}