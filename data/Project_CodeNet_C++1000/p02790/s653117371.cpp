#include <iostream>
#include <cmath>
#include <iomanip>
#include <algorithm>

#include <vector>
#include <array>
#include <map>
#include <set>
#include <stack>
#include <queue>

#define int64 long long
#define uint64 unsigned long long
using namespace std;

int main()
{
	int64 aa, bb;
	cin >> aa >> bb;
	string as, bs;
	for(int64 ii = 0;ii < bb;ii++)
	{
		as += aa + '0';
	}
	for(int64 ii = 0;ii < aa;ii++)
	{
		bs += bb + '0';
	}
	if(as < bs)
	{
		cout << as << endl;
	}
	else
	{
		cout << bs << endl;
	}
	return 0;
}