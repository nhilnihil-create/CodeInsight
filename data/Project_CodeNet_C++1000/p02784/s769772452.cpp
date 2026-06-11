#include <bits/stdc++.h>

using namespace std;

int main()
{
	int H, N;
	cin >> H >> N;
	int s = 0;
	int v;
	for (int i = 0; i < N; ++i)
	{
		cin >> v;
		s += v;
	}
	cout << (s >= H ? "Yes" : "No");


	return 0;
}
