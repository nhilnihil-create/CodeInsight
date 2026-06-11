#include <iostream>
#include <stack>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

#define rep(i,n) for(int i=0; i < n; i++)
using ll =  long long;
using namespace std;
#define pi 3.14159265358979


int main()
{
	int a, b;
	cin >> a >> b;
	int i = 1;
	while((int)(i * 0.08) <= a && (int)(i * 0.1) <= b)
	{
		double x = i * 0.08;
		double y = i * 0.1;
		if ((int)x == a && (int)y == b)
		{
			cout << i;
			return 0;
		}
		i++;
	}
	cout << -1;
	return 0;
}