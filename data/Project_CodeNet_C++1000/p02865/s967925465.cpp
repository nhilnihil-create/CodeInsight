#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
	int n, cnt = 0;
	cin>>n;
	for (int i = 1; i <= n/2; ++i)
	{
		if (i + (n - i) == n && i != (n - i))
		{
			cnt++;
		}
	}
	cout<<cnt;
	cin>>n;
	return 0;
}