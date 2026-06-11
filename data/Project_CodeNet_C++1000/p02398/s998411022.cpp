#include <cstdio>
#include <iostream>
#include <set>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	set<int> s;
	for(int i = 1; i <= c; ++i) {
		if(c % i == 0) {
			s.insert(i);
			s.insert(c / i);
		}
	}
	auto it = s.lower_bound(a);
	int ret = 0;
	while(it != s.end() && *it <= b) {
		++it, ++ret;
	}
	cout << ret << endl;
	return 0;
}