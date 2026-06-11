#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(int argc, char *argv[]) {
	int N;

	cin >> N;

	int n2 = 1 << N;
	vector<int> a(n2);
	
	for (int i = 0; i < n2; i++) {
		cin >> a[i];
	}
	sort(a.begin(), a.end());
	vector<int> s;
	s.push_back(a.back());
	a.back() = -1;

	for (int i = 0; i < N; i++) {
		vector<int> p = s;
		sort(p.begin(), p.end());
		int ai = n2 - 1;
		while (p.size() > 0 && ai >= 0) {
			if (a[ai] == -1) {
				ai--;
				continue;
			}
			if (a[ai] < p.back()) {
				s.push_back(a[ai]);
				p.pop_back();
				a[ai]= -1;
			}
			ai--;
		}
		if (p.size() > 0) {
			cout << "No" << endl;
			return 0;
		}
	}
	cout << "Yes" << endl;

	return 0;
}