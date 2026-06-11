
#include <algorithm>
#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <math.h>
using namespace std;
#define ll long long int

int main(void)
{
	int a, b, d, g, count = 0;
		string S, T, U;
	cin >> g;
	vector<int> vec(g);
	map<char, int> mp;
	for (int i = 0;i < g;i++)
	{
		std::cin >> vec[i];
	}

	for (int i = 1;i < g - 1;i++)
	{
		if (vec[i - 1] < vec[i] && vec[i] < vec[i + 1])
			count++;
		else if(vec[i - 1] > vec[i] && vec[i] > vec[i + 1])
			count++;
	}
		cout << count << endl;
}