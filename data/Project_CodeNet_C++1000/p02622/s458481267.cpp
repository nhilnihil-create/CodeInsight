#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cmath>
#include <map>
#include <stdio.h>
#define IO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
#define pie 3.141592653

using namespace std;


int main()
{
	IO;

	int tot = 0;
	string s, k;
	cin >> s >> k;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] != k[i])
			tot++;
}
	cout << tot;

	return 0;
}
