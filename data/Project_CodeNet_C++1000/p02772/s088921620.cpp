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
	int N;
	cin >> N;

	vector<int> A(N);
	for (size_t i = 0; i < N; i++)
	{
		cin >> A[i];
	}

	bool result = true;
	for (size_t i = 0; i < N; i++)
	{
		if (A[i] % 2 == 0)
		{
			if (A[i] % 3 != 0 && A[i] % 5 != 0)
			{
				result = false;
				break;
			}
		}
	}

	cout << (result ? "APPROVED" : "DENIED") << endl;
	return 0;
}