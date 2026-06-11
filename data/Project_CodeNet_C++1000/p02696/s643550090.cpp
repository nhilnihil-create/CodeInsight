// In the name of God

#include <bits/stdc++.h>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
	long long a, b, n;
	cin >> a >> b >> n;
	
	auto calc = [&](long long x) {
		return (a*(x%b)-((a%b)*x)%b)/b;
	};

	
	cout << max(calc(min(n,b-1)), calc(min(n,a%b?b/(a%b):1)));


	return 0;
}
