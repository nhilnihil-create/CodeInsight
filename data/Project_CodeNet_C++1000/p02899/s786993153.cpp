#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	map<int,int> mp;
	for (int n = 0; n <N; ++n) {
		int num;
		cin >> num;
		mp[num] = n + 1;
	}
	map<int, int >::iterator it;
	for (it = mp.begin(); it != mp.end(); it++){
		if (mp.begin() != it) {
			cout << " ";
		}
		cout << (*it).second;
	}
	return 0;
}
