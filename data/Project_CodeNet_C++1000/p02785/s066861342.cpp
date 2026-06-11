#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	long long N, K;
	cin >> N >> K;
	vector<long long> H(N);
	for (long long i = 0; i < N; i++)
		cin >> H[i];

	sort(H.begin(), H.end(), greater<>());

	long long ans = 0;
	for (long long i = 0; i < N; i++, K--) {
		if (K <= 0) {
			ans += H[i];
		}
	}
	cout << ans << endl;

	return 0;
}