#include <iostream>
#include <string>
#include <vector>
using namespace std;

long long mod = 1000000007;

int main()
{
	string l;
	cin >> l;

	const size_t ls = l.size();

	vector<long long> dp1(ls+1);	// L と同じ
	vector<long long> dp2(ls+1);	// L より小さい

	dp1[0] = 1;
	dp2[0] = 0;

	for(size_t i = 1; i <= ls; ++i){
		if (l[i-1] == '0') {
			dp1[i] = dp1[i-1];
			dp2[i] = (((dp2[i - 1] + dp2[i - 1]) % mod) + dp2[i - 1]) % mod;
		}
		else {
			dp1[i] = (dp1[i - 1] + dp1[i - 1]) % mod;
			dp2[i] = (((((dp2[i - 1] + dp2[i - 1]) % mod) + dp2[i - 1]) % mod) + dp1[i - 1]) % mod;
		}
	}

	cout << (dp1[ls] + dp2[ls]) % mod << endl;

	return 0;
}