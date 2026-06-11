#include <iostream>
#include <vector>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	string s;
	cin >> s;

	long long r = 0;
	long long g = 0;
	long long b = 0;

	for (int i = 0; i < n; i++)
	{
		if (s[i] == 'R') r++;
		else if (s[i] == 'G') g++;
		else b++;
	}

	long long all = r * g * b;
	long long sub = 0;

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			if (s[i] == s[j]) continue;
			int k = j * 2 - i;
			if (k >= n || s[k] == s[i] || s[k] == s[j]) continue;
			sub++;
		}
	}

	cout << all - sub << endl;

	return 0;
}