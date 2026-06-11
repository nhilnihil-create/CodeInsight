#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[1001] = {0};

int main()
{
	int a, b, total=0;
	cin >> a >> b;
	for(int i=0; i<a; i++)
	{
		cin >> arr[i];
	}
	sort(arr, arr+a);
	for(int i=0; i<b; i++)
	{
		total += arr[i];
	}
	cout << total;
}

