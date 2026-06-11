#include <bits/stdc++.h>

using namespace std;

int main()
{

	unordered_set<int> s;
	int N, val;
	cin >> N;
	for (int i = 0; i < N; ++i)
	{
		cin >> val;
		if (s.count(val))
		{
			cout << "NO";
			return 0;
		}
		s.insert(val);
	}
	cout << "YES";
	return 0;
}
