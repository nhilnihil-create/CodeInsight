#include<bits/stdc++.h>
using namespace std;

int cnt;

void insertionSort(vector<int> &v, const int g) {
	int work, k, size = v.size();
	for (int i = g; i < v.size(); ++i) {
		work = v[i];
		k = i - g;
		while (k >= 0 && v[k] > work) {
			v[k + g] = v[k];
			k -= g;
			++cnt;
		}
		v[k + g] = work;
	}
}

void shellSort(vector<int> &v) {
	vector<int> G;
	cnt = 0;
	
	for (int i = 1;;) {
		if (i > v.size()) break;
		G.push_back(i);
		i = 3 * i + 1;
	}
	cout << G.size() << endl;

	reverse(G.begin(), G.end());

	for (auto itr = G.begin(); itr != G.end(); ++itr) {
		cout << *itr;
		if (itr != G.end() - 1) cout << " ";
	}
	cout << endl;

	for (auto itr = G.begin(); itr != G.end(); ++itr) {
		insertionSort(v, *itr);
	}
}

int main() {
	int n;
	vector<int> v;

	cin >> n;

	v.resize(n);

	for (int i = 0; i < v.size(); ++i)
		scanf("%d", &v[i]);

	shellSort(v);
	cout << cnt << endl;

	int size = v.size();
	for (int i = 0; i < size; ++i) {
		cout << v[i];
		if (i != size - 1)  cout << endl;
	}
	return 0;
}

