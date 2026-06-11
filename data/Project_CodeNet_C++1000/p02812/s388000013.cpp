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
	string S;
	cin >> S;

	int count = 0;
	for (size_t i = 0; i < N - 2; i++)
	{
		if (S[i] == 'A' && S[i+1] == 'B' && S[i+2] == 'C')
		{
			count++;
		}
	}

	cout << count << endl;
	return 0;
}