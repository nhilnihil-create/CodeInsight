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
    int A, B, C, D, E;
	cin >> A >> B >> C >> D >> E;

	int nums[5] = {A, B, C, D, E};

	for (size_t i = 0; i < sizeof(nums); i++)
	{
		if (nums[i] == 0)
		{
			cout << (i + 1) << endl;
			return 0;
		}
	}

	return 0;
}