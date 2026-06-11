#include <iostream>
#include <string>
typedef unsigned long long int ull;
using namespace std;

ull power(ull x, ull n, ull M)
{
	ull temp = 1;
	if (n > 0)
	{
		temp = power(x, n / 2, M);
		if (n % 2 == 0)
		{
			temp = (temp * temp) % M;
		}
		else
		{
			temp = (((temp * temp) % M) * x) % M;
		}
	}
	return(temp);
}

void solve()
{
	int m, n;
	cin >> m >> n;
	cout << power(m, n, 1000000007) << endl;
	
}

int main()
{
	solve();
	return(0);
}