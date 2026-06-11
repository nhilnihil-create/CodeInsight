#include <algorithm>
#include <iostream>
#include <vector>
#include <string> 

typedef long long ll;
using namespace std;
const ll m = 1e9 + 7;

int main() {
	int n; cin >> n;
	vector<int>vec(n);
	for (int i = 0; i < n; ++i) {
		cin >> vec[i];
	}
	int cnt = 0;
	sort(vec.begin(), vec.end());
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < i; ++j) {
			for (int k = 0; k < j; ++k) {
				if (vec[k] != vec[j] && vec[j] != vec[i] &&
					vec[k] + vec[j] > vec[i]) {
					cnt++;
				}

			}
		}
	}
	
	cout << cnt << endl;
    return 0;
}