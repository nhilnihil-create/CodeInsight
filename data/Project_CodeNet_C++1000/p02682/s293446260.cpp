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
	int A, B, C, K;
	cin >> A >> B >> C >> K;

	int ans = 0;
	for (int i = 0; i < K; i++)
	{
		if (0 < A)
		{
			ans += 1;
			A--;
		}
		else if (0 < B) {
			B--;
		}
		else if (0 < C) {
			ans -= 1;
			C--;
		}
	}
	cout << ans << endl;

}
