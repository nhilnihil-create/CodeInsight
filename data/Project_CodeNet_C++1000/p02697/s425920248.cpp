#include<iostream>
#include<cmath>
#include<algorithm>
//#include<bitset>

using namespace std;

int n, m;

void add(int &i, int j)
{
	i += j;
	if (i <= 0)
	{
		i = n;
	}
	if (i > n)
	{
		i -= n;
	}
}

int main(void)
{
	cin >> n >> m;

	int i = 1;
	int j = n - 1;
	bool flg = n % 2 == 0;
	for (int c = 0; c < m; c++)
	{
		if (flg && (j - i <= n/2))
		{
			flg = false;
			add(i, 1);
		}
		cout << i << " " << j <<  endl;
		//cout << ":  " << min(abs(j - i), 1000 - abs(j - i)) << endl;
		add(i, 1);
		add(j, -1);
	}
	return 0;
	
}