#include <iostream>
using namespace std;

const int mxN = 2e3 + 5;
int cnt[mxN];

int main() {
	int n, x, y;
	cin >> n >> x >> y;
	
	
	
	// |j - i|, |x - i| + 1 + |j - y|, |y - i| + 1 + |j - x|
	for(int i = 1; i <= n; ++i)
		for(int j = i + 1; j <= n; ++j) 
			++cnt[min(min(abs(j - i), abs(x - i) + 1 + abs(j - y)), abs(y - i) + 1 + abs(j - x))];
	for(int i = 1; i < n; ++i)
		cout << cnt[i] << '\n';
}			
