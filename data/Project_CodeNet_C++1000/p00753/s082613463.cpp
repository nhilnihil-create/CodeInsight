#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

vector<int> getPrimeList(int n)
{
	vector<int> table(n+1, 0);
	
	for(int i = 2; i <= n; i++)
	{
		table[i] = true;
		for(int j = 2; j * j <= i; j++)
		{
			if(i % j == 0)
			{
				table[i] = false;
				break;
			}
		}
	}
	
	return table;
}

int main()
{
	vector<int> table(getPrimeList(123456 * 2));
	
    for(int n; cin >> n && n;)
	{
		cout << accumulate(table.begin() + n + 1, table.begin() + 2 * n + 1, 0) << endl;
	}
}