#include<iostream>
#include<string>
#include<vector>
using namespace std;
int main()
{
	long long  n, a, b;
	cin >> n >> a >> b;
	long long ans = 0;
	long long key = n / (a + b);
	long long dog = n % (a + b);
	if (dog > a)dog = a;
	ans = key*a + dog;
	cout << ans;
	return 0;
}

