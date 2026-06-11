#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main()
{
	string s;
	cin >> s;
	int n = s.size();
	const int MOD = 2019;
	auto p = vector<int>(n + 1);
	auto a = vector<int>(n + 1);
	auto d = vector<int>(n + 1);
	auto m = map<int, long long int>();
	++m[0];
	p[0] = 1;
	for(int i = 1; i <= n; ++i){
		a[i] = ((s[n - i] - '0') * p[i - 1]) % MOD;
		d[i] = (a[i] + d[i - 1]) % MOD;
		p[i] = (p[i - 1] * 10) % MOD;
		++m[d[i]];
	}
	long long int ans = 0;
	for(auto mm : m){
		ans += (mm.second * (mm.second - 1) / 2);
	}
	cout << ans << endl;
	return 0;
}