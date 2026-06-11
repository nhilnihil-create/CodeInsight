#include <iostream>
#include<vector>
#include <map>
#include <set>
#include <queue>
using namespace std;

int main() {
	int n, m;
	cin >> n >> m;
	vector<int> vi(n, 0);
	map<int, vector<int>> mp;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		mp[x].push_back(y);
		mp[y].push_back(x);		
	}
 
	int cnt1 = 1;
	for (int i = 0; i < n; i++) {
		if (vi[i] != 0) continue;
		cnt1++;
		queue<int> q;
		q.push(i + 1);
 
		while (!q.empty()) {
			int size = q.size();
			for (int j = 0; j < size; j++) {
				int el = q.front(); q.pop();
				vi[el - 1] = cnt1;
				for (int ii = 0; ii < mp[el].size(); ii++) {
					if (vi[mp[el][ii] - 1] == 0)
						q.push(mp[el][ii]);
				}
			}
		}

	}
	set<int> st;
	for (auto el : vi) st.insert(el);
	cout << st.size() - 1 << "\n";
	return 0;
}