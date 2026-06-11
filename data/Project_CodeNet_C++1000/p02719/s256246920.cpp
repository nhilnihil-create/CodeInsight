#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int main()
{
	long long int n, k;
	cin >> n >> k;
	if(n%k < k-n%k)
	{
		cout << n%k;
	}
	else
	{
		cout << k-n%k;
	}
}

