#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void outStr(vector<int>& ary) {

	string aryStr = "";
	for (int i = 0; i < ary.size(); i++)
	{
		aryStr = aryStr + to_string(ary[i]);
		if (i < ary.size() - 1) aryStr = aryStr + " ";
	}

	cout << aryStr << endl;
	return;
}


int insertSort(vector<int>& ary, int g) {

	int v = 0;; int j = 0; int cnt = 0;
	for (int i = g; i < ary.size();i++) {
		v = ary[i];
		j = i - g;

		while (j >= 0 && ary[j] > v)
		{
			ary[j + g] = ary[j];
			j = j - g;
			cnt++;
		}
		ary[j + g] = v;

	}

	return cnt;
}



int main() {

	int N;
	cin >> N;
	vector<int> ary(N);
	for (int i = 0; i < N; i++) {
		cin >> ary[i];
	}

	vector<int> G;
	int h = 0;
	while (h <= N /5)
	{
		h = 3 * h + 1;
		G.push_back(h);
	}
	reverse(G.begin(), G.end());

	int cnt = 0;
	int m = G.size();

	for (int i = 0;i < m;i++) {
		cnt += insertSort(ary, G[i]);
	}


	cout << m << endl;
	outStr(G);
	cout << cnt << endl;

	for (int i = 0; i < N; i++) {
		cout << ary[i] << endl;

	}

	return 0;
}

