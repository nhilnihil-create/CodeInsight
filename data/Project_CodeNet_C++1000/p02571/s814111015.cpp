#include <iostream>
#include <iomanip>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
#include <numeric>
#include <math.h>

using namespace std;
void func()
{
	string S,T;
	cin >> S;
	cin >> T;

	int ans = INT_MAX;
	for (int i = 0; i < S.size() - T.size()+1; ++i)
	{
		int tmp(0);
		for (int j = 0; j < T.size(); ++j)
		{
			if (S[i + j] != T[j])
				++tmp;
		}
		ans = min(ans, tmp);
	}
	cout << ans << endl;
}

int main() {
//	while(1)
	func();
	return 0;
}
