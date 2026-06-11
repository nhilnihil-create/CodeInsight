#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	long long int a, num=100, t=0;
	cin >> a;
	while(num < a)
	{
		num += num/100;
		t++;
	}
	cout << t;
}

