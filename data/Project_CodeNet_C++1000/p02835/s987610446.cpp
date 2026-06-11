#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int x, y, z;
	cin >> x >> y >> z;

	int s = x + y + z;
	if (s >= 22)
	{
		cout << "bust";
	}
	else
	{
		cout << "win";
	}
	
}
