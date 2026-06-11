#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int N;
	cin >> N;
	for (int i = N; i; i--)
	{
		for (int j = 1; j < i; j++) cout << __builtin_ctz(j) + 1 << " ";
		cout << endl;
	}
	return 0;
}
