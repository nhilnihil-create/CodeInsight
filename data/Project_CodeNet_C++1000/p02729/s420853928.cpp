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
int calcNumOfCombination(int n, int r)
{
    int num = 1;
    for(int i = 1; i <= r; i++)
    {
        num = num * (n - i + 1) / i;
    }
    return num;
}

int main()
{
	int n, m;
	cin >> n >> m;

	int a = calcNumOfCombination(n, 2);
	int b = calcNumOfCombination(m, 2);

	cout << a + b << endl;
    return 0;
}