#include <iostream>
using namespace std;
bool isPrime(int num);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int x;
	cin>>x;
	bool a=true, b;
	while(a)
	{
		b=isPrime(x);
		if(!b)	x++;
		else
		{
			cout<<x;
			a=false;
		}
	}
}
bool isPrime(int num)
{
	bool flag = true;
	for (int i = 2; i <= num / 2; i++)
	{
		if (num % i == 0)
		{
			flag = false;
			break;
		}
	}
	return flag;
}
