#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

vector<string> vec;
int N;

void dfs(vector<int> rem, vector<vector<int>> V) {
	if (rem.size() == 0) {
		string S = "";
		for (int i = 0; i < N; i++) S += "0";
		for (int i = 0; i < V.size(); i++) {
			for (int j : V[i]) S[j] = ('a' + i);
		}
		vec.push_back(S);
		return;
	}

	for (int i = 0; i < (1 << rem.size()); i++) {
		int bit[12];
		for (int j = 0; j < rem.size(); j++) bit[j] = (i / (1 << j)) % 2;
		if (bit[0] != 1) continue;

		vector<int> F, G;
		for (int j = 0; j < rem.size(); j++) {
			if (bit[j] == 0) F.push_back(rem[j]);
			else G.push_back(rem[j]);
		}
		vector<vector<int>> S = V;
		S.push_back(G);
		dfs(F, S);
	}
}

int main() {
	cin >> N;
	vector<int> L; for (int i = 0; i < N; i++) L.push_back(i);
	dfs(L, vector<vector<int>>{});

	sort(vec.begin(), vec.end());
	for (int i = 0; i < vec.size(); i++) cout << vec[i] << endl;
	return 0;
}