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
	int N, K;
	cin >> N >> K;

	map<int, bool> m;
	for(int i = 0; i < N; i++)
	{
		m[i] = false;
	}

	for(int i = 0; i < K; i++)
	{
		int d;
		cin >> d;
		for(int j = 0; j < d; j++)
		{
			int a;
			cin >> a;
			m[a-1] = true;
		}
	}

	int count = 0;
	for(int i = 0; i < N; i++)
	{
		if(!m.at(i))
		{
			count++;
		}
	}

	cout << count << endl;
}