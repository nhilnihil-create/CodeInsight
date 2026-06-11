#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	long long int n, total=0;
	cin >> n;
	total += n/500*1000;
	n -= n/500*500;
	total += n/5*5;
	cout << total;
}

