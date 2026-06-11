#include<iostream>
#include<vector>
#include<list>
#include<math.h>


using namespace std;
using vec = vector<int>;
using lst = list<int>;

bool check(int x, lst & sosu)
{
	for(auto s : sosu)
	{
		if (sqrt(x) < s)return true;
		if (x%s == 0)return false;
	}
	return true;
}


int main()
{
	vec count(123456 * 2 + 1);
	lst sosu;
	
	count[0] = 0;
	count[1] = 0;
	count[2] = 1;
	sosu.emplace_back(2);

	for (int i = 3; i < count.size(); ++i)
	{
		count[i] = count[i - 1];
		if (check(i, sosu))
		{
			++count[i];
			sosu.emplace_back(i);
		}
	}


	int n;
	while (true)
	{
		cin >> n;

		if (n == 0)return 0;
		cout << count[2 * n] - count[n] << endl;
	}
}
