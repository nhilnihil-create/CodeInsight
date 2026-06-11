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

	if (A / 10 == 0 && B / 10 == 0)
	{
		cout << A*B;
	}
	else
	{
		cout << -1;
	}
	
}
