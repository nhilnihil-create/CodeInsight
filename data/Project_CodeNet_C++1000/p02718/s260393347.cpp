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
	int N, M;
	cin >> N >> M;

	vector<int> vec(N);
	int sum = 0;
	for (size_t i = 0; i < N; i++)
	{
		cin >> vec[i];
		sum += vec[i];
	}

	int count = 0;
	for (size_t i = 0; i < N; i++)
	{
		if (sum / (float)(4 * M) > (float)vec[i])
		{
			continue;
		}
		count++;
	}

	cout << (count >= M ? "Yes" : "No") << endl;

	return 0;
}