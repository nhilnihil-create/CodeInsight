#include <iostream>

using namespace std;
int Solve(int a, int b)
{
	int Array[10000];
	int sum = 0;
	int ans;
	for (int i = 0; i < b; i++)
	{
		cin >> Array[i];
		sum += Array[i];
	}
	ans = a - sum;
	if (ans < 0)
	{
		return -1;
	}
	else return ans;
}
int main()
{
	int x, y;
	cin >> x >> y;
	cout << Solve(x, y);
	return 0;
}