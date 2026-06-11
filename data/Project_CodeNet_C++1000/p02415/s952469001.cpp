#include<cstdio>
#include<vector>
#include<algorithm>
#include<utility>
#include<numeric>
#include<iostream>
#include<array>
#include<string>
#define _USE_MATH_DEFINES

#include<math.h>
#include<unordered_map>

#define min(a,b) (a)>(b)?(b):(a)
#define max(a,b) (a)>(b)?(a):(b)

using namespace std;

int main()
{
	string input;
	getline(cin, input);

	const int ul = 'a' - 'A';
	for (auto& c : input)
	{
		if ('A' <= c&&c <= 'Z')
		{
			c += ul;
		}
		else if ('a' <= c&&c <= 'z')
		{
			c -= ul;
		}
	}

	cout << input << endl;

	return 0;
}