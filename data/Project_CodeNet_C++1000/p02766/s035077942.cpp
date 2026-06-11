#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101][101] = {0};

int main()
{
	int n, k, t=0;
	cin >> n >> k;
	while(n > 0)
	{
		n /= k;
		t++;
	}
	cout << t;
}

