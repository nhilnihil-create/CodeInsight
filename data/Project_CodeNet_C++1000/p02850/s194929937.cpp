#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	int n;
	cin >> n;
	vector<pair<int,int>>imp(n-1);
	for (int i = 0; i < n-1; i++) {
		cin >> imp.at(i).first >> imp.at(i).second;
		imp.at(i).first--;
		imp.at(i).second--;
	}
	map<pair<int,int>,int>imps;
	for (int i = 0; i < n - 1; i++)imps.insert({ imp.at(i),0 });
	vector<vector<int>>graph(n, vector<int>(0));
	for (int i = 0; i < n - 1; i++) {
		int x, y;
		x = imp.at(i).first;
		y = imp.at(i).second;
		graph.at(x).push_back(y);
		graph.at(y).push_back(x);
	}
	vector<int>parent(n, -1);
	queue<int>search;
	search.push(0);
	parent.at(0) = 0;
	while (search.size() > 0) {
		int a = search.front();
		vector<int> b = graph.at(a);
		for (int i = 0; i < b.size(); i++) {
			if (parent.at(b.at(i)) == -1) {
				parent.at(b.at(i)) = a;
				search.push(b.at(i));
			}
		}
		search.pop();
	}
	search.push(0);
	int mx = 0;
	while (search.size() > 0) {
		int a = search.front();
		vector<int> b = graph.at(a);
		set<int>forbid;
		if (a != 0)forbid.insert(imps.at({ parent.at(a),a }));
		int tmp = 1;
		for (int i = 0; i < b.size(); i++) {
			pair<int, int> x = { a,b.at(i) };
			if (x.first > x.second)swap(x.first, x.second);
			while (true) {
				if (forbid.count(tmp))tmp++;
				else break;
			}
			if (imps.at(x) == 0) {
				imps.at(x) = tmp;
				tmp++;
				search.push(b.at(i));
			}
		}
		mx = max(mx, tmp);
		search.pop();
	}
	cout << mx-1 << endl;
	for (int i = 0; i < n - 1; i++) {
		cout << imps.at(imp.at(i)) << endl;
	}
}