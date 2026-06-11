#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int A,B;
	cin >> A >> B;

	int s = A - 2 * B;

	if (s <= 0)
	{
		cout << 0;
	}
	else
	{
		cout << s;
	}
	
}
