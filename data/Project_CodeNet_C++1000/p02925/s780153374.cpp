#include "bits/stdc++.h"
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std; 
typedef pair<int, int> P;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> data(N, vector<int>(N - 1));
	for (int n = 0; n < N; ++n) {
		for (int m = 0; m < N - 1; ++m) {
			int num;
			cin >> num;
			num--;
			data[n][m] = num;
		}
		reverse(data[n].begin(), data[n].end());
	}
	vector<pair<int,int>>q;
	auto check = [&](int i) {
		if (0 == data[i].size()) {
			return;
		}	
		int j = data[i].back();
		if (0 == data[j].size()) {
			return;
		}
		if (i == data[j].back()) {
			q.push_back(make_pair(min(i,j),max(j,i)));
		}
	};
	for (int i = 0; i < N; ++i){
		check(i);
	}
	int day = 0;
	while (q.size() > 0) {
		day++;
		sort(q.begin(), q.end());
		q.erase(unique(q.begin(), q.end()), q.end());
		vector<P> prevQ;
		swap(prevQ, q);
		for (P p : prevQ) {
			int i = p.first, j = p.second;
			data[i].pop_back();
			data[j].pop_back();
		}
		for (P p : prevQ) {
			int i = p.first, j = p.second;
			check(i);
			check(j);
		}
	}
	rep(i, N) {
		if (data[i].size() != 0) {
			puts("-1");
			return 0;
		}
	}
	cout << day << endl;
	return 0;
}