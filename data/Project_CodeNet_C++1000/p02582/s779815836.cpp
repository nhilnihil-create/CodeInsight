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
    string S;
	cin >> S;

	int maxCount = 0;
	int count = 0;
	for (size_t i = 0; i < S.length(); i++)
	{
		if (S[i] == 'R')
		{
			count++;
			maxCount = max(maxCount, count);
		}
		else
		{
			count = 0;
		}
	}
	

	cout << maxCount << endl;

	return 0;
}