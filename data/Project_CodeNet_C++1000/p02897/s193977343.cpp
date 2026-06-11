#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<stack>
using namespace std;

int main()
{
	int N;
	cin >> N;

	if (N % 2 == 0)
	{
		cout << 1.0 / 2;
	}
	else
	{
		int s = N / 2;
		s = N - s;

		cout << s * 1.0 / N;
	}
	
}
