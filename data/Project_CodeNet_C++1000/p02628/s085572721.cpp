#include <iostream>
#include <string>
#include <algorithm>
#include <cmath>
#include <vector>
#include <ctype.h>
#include <stdlib.h>
#include <map>
using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector<int> P(N);

	for (int i = 0; i < N; i++)
	{
		cin >> P[i];
	}

	sort(P.begin(), P.end());

	int ans = 0;
	for (int i = 0; i < K; i++)
	{
		//cout << P[i] << endl;
		ans += P[i];
	}
		cout << ans << endl;

}
