#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;
typedef long long llong;

void solve_test()
{
	string buffer;
	cin >> buffer;
	deque<char> s;
	for (char symbol : buffer)
		s.push_back(symbol);
	int nQ, begin = 1, end = 2;
	cin >> nQ;
	while (nQ--)
	{
		int cmd;
		cin >> cmd;
		if (cmd == 1)
			swap(begin, end);
		else
		{
			int to;
			char value;
			cin >> to >> value;
			if (to == 1 && to == begin) s.push_front(value);
			else if (to == 1) s.push_back(value);
			else
			{
				if (to == end) s.push_back(value);
				else s.push_front(value);
			}
		}
	}
	if (begin != 1)
		reverse(s.begin(), s.end());
	for (char symbol : s)
		cout << symbol;
	cout << "\n";
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int tests = 1;
	//cin >> tests;
	while (tests--)
		solve_test();

	return 0;
}
