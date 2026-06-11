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
    int K, A, B;
	cin >> K >> A >> B;

	bool result = false;
	for (size_t i = A; i <= B; i++)
	{
		if (i % K == 0)
		{
			result = true;
			break;
		}
	}

	cout << (result ? "OK" : "NG") << endl;

	return 0;
}