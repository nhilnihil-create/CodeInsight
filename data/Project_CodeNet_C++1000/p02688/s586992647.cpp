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
	int d = 0;
	vector<bool> KA(N,false);
	for (int i = 0; i < K; i++)
	{
		cin >> d;
		int A = 0;
		for (int i = 0; i < d; i++)
		{
			cin >> A;
			KA[A - 1] = true;
		}
	}

	int ans = 0;
	for (int i = 0; i < N; i++)
	{
		if (KA[i] == true) {
			ans++;
		}
	}
	ans = N - ans;
	cout << ans << endl;

}
