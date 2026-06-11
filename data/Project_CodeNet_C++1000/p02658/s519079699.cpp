#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>

using namespace std;


#define kotei (1000000000000000000)
int main() {
    uint64_t N,Ai;
	cin >> N;

	uint64_t ans(1);

	for (size_t i = 0; i < N; ++i)
	{
		cin >> Ai;
		if (Ai == 0)
		{
			ans = 0;
			break;
		}
		else if (ans < UINT64_MAX/Ai)
		{
			ans *= Ai;
		}
		else
		{
			ans = UINT64_MAX;
		}

		if (ans > kotei)
		{
			ans = UINT64_MAX;
		}
	}

	if (ans == UINT64_MAX)
		cout << -1 << endl;
	else
		cout << ans << endl;
	return 0;
}

