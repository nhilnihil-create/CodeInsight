#include <iostream>
#include <string.h>

using namespace std;
bool IsPrime[250000];
int PrimeCount[250000];
void calc()
{
	memset(IsPrime, 1, sizeof(bool) * 250000);
	int count = 0;
	PrimeCount[0] = count;
	PrimeCount[1] = count;
	for(int i = 2; i < 250000; ++i)
	{
		if(IsPrime[i])
		{
			count++;
			for(int j = 2 * i; j < 250000; j += i)
			{
				IsPrime[j] = false;
			}
		}
		PrimeCount[i] = count;
	}
}

void solve()
{
	calc();
	int n;
	while(cin >> n, n)
	{
		cout << PrimeCount[2 * n] - PrimeCount[n] << endl;
	}
}

int main()
{
	solve();
	return(0);
}