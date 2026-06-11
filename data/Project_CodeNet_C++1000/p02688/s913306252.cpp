#include <iostream>
#include <sstream>
#include <algorithm>
#include <string>
#include <cmath>
using namespace std;

int arr[101] = {0};

int main()
{
	int n, k, total=0;
	cin >> n >> k;
	for(int i=0; i<k; i++)
	{
		int a;
		cin >> a;
		for(int j=0; j<a; j++)
		{
			int b; 
			cin >> b;
			arr[b] ++;
		}
	}
	for(int i=1; i<=n; i++)
	{
		if(arr[i] == 0)
		{
			total ++;
		}
	}
	cout << total;
}

