#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

int main() {
	int a, b;
	cin >> a >> b;
	set<int> s;
	for (int i = 1; i <= 3; i++) {
		s.insert(i);
	}
	s.erase(a);
	s.erase(b);
	cout << *s.begin();
	return 0;
}
