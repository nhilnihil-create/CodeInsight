#include <iostream>
#include <vector>
using namespace std;

int n, m, a, b, w = 0;
vector<int> r[100001];
bool f[100001];

void ck(int k) {
	for (int i = 0; i < r[k].size(); i++) {
		int j = r[k][i];
		if (!f[j]) {
			f[j] = 1;
			ck(j);
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		cin >> a >> b;

		r[a].push_back(b);
		r[b].push_back(a);
	}

	for (int i = 1; i <= n; i++) {
		if (!f[i]) {
			w++;
			f[i] = 1;
			ck(i);
		}
	}

	cout << w - 1 << endl;
}
