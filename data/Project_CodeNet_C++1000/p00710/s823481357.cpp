#include <iostream>
#include <algorithm>
#include <numeric>
#include <functional>
using namespace std;

int main() {
	int n, r;
	while(cin >> n >> r, n || r) {
		vector<int> v(n);
		iota(v.rbegin(), v.rend(), 1);
		
		for(int i = 0; i < r; ++i) {
			int p, c;
			cin >> p >> c;
			p--;
			auto temp = v;
			for(int j = 0; j < c; ++j) {
				temp[j] = v[p + j];
			}
			
			for(int j = 0; j < p; ++j) {
				temp[c + j] = v[j];
			}
			
			swap(v, temp);
		}
		cout << v[0] << endl;
	}
	return 0;
}