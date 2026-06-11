#include <iostream>
#include <string>
#include <vector>
#include <bitset>

using namespace std;

int parity_comb(int n, int r)
{
	int cnt = bitset<32>(n ^ r ^ (n - r)).count();
	return cnt == 0 ? 1 : 0;
}

int solve(int N, vector<int>& a)
{
	int p = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] == 1) {
			p += parity_comb(N - 1, i);
		}
	}
	if (p & 1) {
		return 1;
	}
	for (int i = 0; i < N; ++i) {
		if (a[i] == 1) {
			return 0;
		}
	}

	p = 0;
	for (int i = 0; i < N; ++i) {
		if (a[i] == 2) {
			p += parity_comb(N - 1, i);
		}
	}
	return 2 * (p & 1);

}


int main()
{
	int N;
	cin >> N;
	string s;
	cin >> s;

	vector<int> a(N);
	for (int i = 0; i < N; ++i) {
		a[i] = s[i] - '1';
	}
	
	cout << solve(N, a) << endl;
}
