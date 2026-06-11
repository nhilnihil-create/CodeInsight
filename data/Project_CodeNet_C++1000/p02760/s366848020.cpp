#include<iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	vector<uint16_t> A;
	for (size_t i = 0; i < 9; ++i)
	{
		uint16_t a_ij;
		cin >> a_ij;
		A.push_back(a_ij);
	}

	size_t N;
	cin >> N;
	if (N >= 3)
	{
		vector<uint16_t>::iterator itr;
		uint16_t hit(0);
		for (size_t i = 0; i < N; ++i)
		{
			uint16_t bn(0);
			cin >> bn;
			itr = find(A.begin(), A.end(), bn);
			if (itr != A.end())
				hit |= 1 << distance(A.begin(), itr);
		}
		const uint16_t tate(1 | 1 << 3 | 1 << 6);
		const uint16_t yoko(1 | 1 << 1 | 1 << 2);
		const uint16_t naname1(1 | 1 << 4 | 1 << 8);
		const uint16_t naname2(1<<2 | 1 << 4 | 1 << 6);

		for (size_t i = 0; i < 3; ++i)
		{
			uint16_t check;
			check = tate << i;
			if ((hit & check) == check)
			{
				cout << "Yes" << endl;
				return 0;
			}
			check = yoko << i*3;
			if ((hit & check) == check)
			{
				cout << "Yes" << endl;
				return 0;
			}
		}
		if ((hit & naname1) == naname1
			|| (hit & naname2) == naname2)
		{
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;

	return 0;
}