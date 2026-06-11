#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

using namespace std;

int L;

int next_sequence(int n)
{
	string N, L_, R_;

	N = to_string(n);

	for (int i = N.size(); i < L; i++)
	{
		N += '0';
	}

	L_ = N;
	R_ = N;

	sort(L_.begin(), L_.end());
	sort(R_.begin(), R_.end(), greater<char>());

	return stoi(R_) - stoi(L_);
}

int main()
{
	vector<int> a; int val;

	while (true)
	{
		cin >> val >> L;

		if (val == 0 && L == 0)
		{
			break;
		}
		else
		{
			a.clear();
		}

		a.push_back(val);

		int ptr = 0;

		while (true)
		{
			ptr++;

			a.push_back(next_sequence(a[ptr - 1]));

			for (int i = 0; i < ptr; i++)
			{
				if (a[ptr] == a[i])
				{
					cout << i << ' ' << a[i] << ' ' << ptr - i << endl;

					goto Exit;
				}
			}
		}

	Exit:;
	}

	return 0;
}