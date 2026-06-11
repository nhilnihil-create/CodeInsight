#include <iostream>
#include <set>
using namespace std;

const int mxN = 2e5 + 5;
int a[mxN];

int main() {
	int n;
	cin >> n;
	for(int i = 1; i <= n; ++i)
		cin >> a[i];
	int answer = 1;
	set<int> s;
	s.insert(a[1]);
	for(int i = 2; i <= n; ++i) {
		answer += a[i] <= *s.begin();
		s.insert(a[i]);
	}
	cout << answer;
}
