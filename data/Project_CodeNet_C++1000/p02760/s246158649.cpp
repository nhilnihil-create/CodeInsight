#include <iostream>
#include <vector>
#include <algorithm>
#include <stdio.h>
#include <math.h>
#include <string>
#include <cctype>
#include <map>
#include <limits>
#include <iomanip>

using namespace std;

const int mod = 1000000007;
#define ARRAY_LENGTH(array) (sizeof(array) / sizeof(array[0]))
#define ll long long

int main()
{
	vector< vector<int> > A(3, vector<int>(3));

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			cin >> A.at(i).at(j);
		}
	}

	int N;
	cin >> N;

	vector<int> b(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> b[i];
	}

	vector< vector<bool> > s(3, vector<bool>(3));
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			int num = A.at(i).at(j);
			if (find(begin(b), end(b), num) != end(b))
			{
				s.at(i).at(j) = true;
			}
		}
	}

	if (s.at(0).at(0) && s.at(1).at(0) && s.at(2).at(0))
	{
		cout << "Yes" << endl;
	}
	else if (s.at(0).at(1) && s.at(1).at(1) && s.at(2).at(1))
	{
		cout << "Yes" << endl;
	}
	else if (s.at(0).at(2) && s.at(1).at(2) && s.at(2).at(2))
	{
		cout << "Yes" << endl;
	}
	else if (s.at(0).at(0) && s.at(0).at(1) && s.at(0).at(2))
	{
		cout << "Yes" << endl;
	}
	else if (s.at(1).at(0) && s.at(1).at(1) && s.at(1).at(2))
	{
		cout << "Yes" << endl;
	}
	else if (s.at(2).at(0) && s.at(2).at(1) && s.at(2).at(2))
	{
		cout << "Yes" << endl;
	}
	else if (s.at(0).at(0) && s.at(1).at(1) && s.at(2).at(2))
	{
		cout << "Yes" << endl;
	}
	else if (s.at(0).at(2) && s.at(1).at(1) && s.at(2).at(0))
	{
		cout << "Yes" << endl;
	}
	else
	{
		cout << "No" << endl;
	}

	return 0;
}