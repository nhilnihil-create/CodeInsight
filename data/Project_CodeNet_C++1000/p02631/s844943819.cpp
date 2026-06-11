#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> av(n);
	vector<vector<int>> c(32);
	for(int i = 0; i < n; ++i){
		int a;
		cin >> a;
		av[i] = a;
		for (int j = 0; j < 32; ++j) {
			if (a % 2 == 0) {
				c[j].push_back(i);
			}
			a >>= 1;
		}
	}

	for (int i = 0; i < n; ++i) {
		long long ret = 0;
		for (int j = 0; j < 32; ++j) {
			int t = 1;
			if (av[i] % 2 == 0) {
				t = 0;
			}
			if (c[j].size() % 2 == 1) {
				t = (t + 1) % 2;
			}
			av[i] >>= 1;
			ret += t << j;
		}
		cout << ret << " ";
	}
	cout << endl;

	return 0;
}