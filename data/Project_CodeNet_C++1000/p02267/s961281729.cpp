#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int> vec(n);
	for (int i = 0; i < n; i++)cin >> vec[i];
	cin >> n;

	int counter = 0;
	for (int i = 0; i < n; i++) {
		int t;cin >> t;
		if (find(vec.begin(), vec.end(), t) != vec.end()) {
			counter++;
		}
	}
	cout << counter << endl;
}