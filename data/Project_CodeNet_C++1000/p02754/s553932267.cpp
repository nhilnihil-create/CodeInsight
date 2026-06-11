#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	long long int n, a, b, total=0;
	cin >> n >> a >> b;
	total = n/(a+b)*a;
	n %= (a+b);
	if(n > a)
	{
		total += a;
	}
	else
	{
		total += n;
	}
	cout << total;
}

