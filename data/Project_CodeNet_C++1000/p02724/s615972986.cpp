#include <iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<cmath>
#include<set>

using namespace std;

int main()
{
	int X;
	cin >> X;

	int n500 = X / 500;
	int n5 = (X - 500 * n500) / 5;

	cout << 1000 * n500 + 5 * n5 << endl;

	
}