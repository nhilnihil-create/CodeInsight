#include<iostream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<map>
using namespace std;
int main() {
	int n, r;
	while (cin >> n >> r&&n != 0 && r != 0) {
		list<int>a[2];
		for (int i = n; i >= 1; i--) {
			a[0].push_back(i);
		}
		int p, c;
		list<int>::iterator it = a[0].begin(),it2;
		for (int z = 0; z < r; z++) {
			cin >> p >> c;
			it = a[0].begin();
			a[1].clear();
			for (int i = 1; i < p; i++) it++;
			for (int i = 0; i < c; i++) {
				a[1].push_back(*it);
				it2 = it;
				it2++;
				a[0].erase(it);
				it = it2;
			}
			a[0].insert(a[0].begin(), a[1].begin(), a[1].end());
		}
		it = a[0].begin();
		cout << (*it) << endl;
	}
} 