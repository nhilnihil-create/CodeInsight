#include <iostream>
#include <list>
#include <cmath>

using namespace std;

int main() {
	int n;
	while ((cin >> n),n != 0) {
		list<int> s;
		for (int i = 2; i < sqrt(2 * n) + 1; i++) s.push_back(i);
		for (auto itr = s.begin(); itr != s.end(); itr++) {
			int val = *itr;
			s.remove_if([&](int p){ return p > val && p % val == 0; });
		}
		list<int> dst;
		for (int i = n+1; i <= 2 * n; i++) dst.push_back(i);
		for (auto itr = s.begin(); itr != s.end(); itr++) {
			int val = *itr;
			dst.remove_if([&](int p){ return p > val && p % val == 0; });
		}
		cout << dst.size() << endl;
	}
	return 0;
}