#include "bits/stdc++.h"
#include<unordered_map>
#include<unordered_set>
#pragma warning(disable:4996)
using namespace std;
using ld = long double;
template<class T>
using Table = vector<vector<T>>;
const ld eps=1e-9;

//// < "D:\D_Download\Visual Studio 2015\Projects\programing_contest_c++\Debug\a.txt"
vector<int>topo_sort(const vector<vector<int>>&edges) {
	int size_ = edges.size();
	vector<int>nums(size_);	
	for(const auto& es:edges){
		for (auto e : es) {
			nums[e]++;
		}
	}
	queue<int>que;
	for (int i = 0; i < size_; ++i) {
		if (!nums[i]) {
			que.push(i);
		}
	}
	vector<int>topo;
	while (!que.empty()) {
		int ver(que.front());
		topo.push_back(ver);
		que.pop();
		for (auto e : edges[ver]) {
			nums[e]--;
			if (!nums[e])que.push(e);
		}
	}
	if (topo.size() == size_)return topo;
	else return vector<int>();
}
int main() {
	int V, E; cin >> V >> E;
	vector<vector<int>>edges(V);
	for (int i = 0; i < E; ++i) {
		int s, t; cin >> s >> t;
		edges[s].push_back(t);
	}
	auto vs=topo_sort(edges);
	for (auto v : vs) {
		cout << v << endl;
	}
	return 0;
}