#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

int main() {
	int N;
	cin >> N;

	map<int, int> mp;
	for (int i = 0; i < N - 1; ++i) {
		int a;
		cin >> a;
		mp[a]++;
	}

	for (int i = 1; i <= N; ++i) {
		cout << mp[i] << endl;
	}
	return 0;
}
