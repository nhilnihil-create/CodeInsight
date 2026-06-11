#include <iostream>
using namespace std;

int main()
{
	int k;
	cin >> k;
	auto gcd = [](int a, int b, int c) -> int {
		auto f = [](int x, int y) -> int {
			int t;
			while((t = x % y) != 0){
				x = y;
				y = t;
			}
			return y;
		};
		return f(f(a, b), c);
	};
	int ans = 0;
	for(int i = 1; i <= k; ++i){
		for(int j = 1; j <= k; ++j){
			for(int s = 1; s <= k; ++s){
				ans += gcd(i, j, s);
			}
		}
	}
	cout << ans << endl;
	return 0;
}