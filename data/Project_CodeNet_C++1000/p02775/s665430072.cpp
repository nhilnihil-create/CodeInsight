// 043.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <climits>
#include <algorithm>

using namespace  std;

typedef long long ll;

int join(int a[], int size)
{
	
	for (int i = 0; i < size-2; ++i)
	{
		const auto diff = abs(a[i] - a[i + 2]);
		if (a[i] == a[i + 2]) a[i] = 0;		
		else if (diff == 1) { a[i] = 1; }
		else
		{
			if (a[i + 1] == 2) a[i] = 0;
			else a[i] = 2;
		}
	}

	if (size == 2) return abs(a[0]- a[1]);
	return join(a, size - 2);
}

int main()
{
	//A
   /* int a, b, c;
	cin >> a >> b >> c;

	bool is_equal =
		a == b && a != c ||
		a == c && a != b ||
		b == c && b != a;
	cout << (is_equal ? "Yes" : "No");*/

	//B
	/*int n;
	cin >> n;
	vector<int> a(n);
	int ai;
	for (int i = 0; i < n; ++i)
	{
		cin >> ai;
		a[i] = ai;
	}

	bool is_approved = true;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] % 2 == 0)
		{
			if (a[i] % 3 != 0 && a[i] % 5 != 0)
			{
				is_approved = false;
				break;
			}
		}
	}

	cout << (is_approved ? "APPROVED" : "DENIED");*/


	//C
	/*int n;
	cin >> n;

	map<string, int> votes;

	int max = -1;

	string s;
	for (int i = 0; i < n; ++i)
	{
		cin >> s;
		votes[s]++;
		if (votes[s] > max) max = votes[s];
	}


	for (const auto& item :votes)
	{
		if (item.second == max)
		{
			cout << item.first << "\n";
		}
	}*/


	//D
	

	//E
	string n;
	cin >> n;

	//pd[i][j] - оптимальное число монет для числа 0..i (с конца), j - ждем ли сдачу
	int dp0, dp1;

	int res = 0;
	int prev = 0;
	for (ll i = n.length() - 1; i >= 0; --i)
	{
		int a = n[i] - '0';
		if (i == n.length() - 1)
		{
			dp0 = a;
			dp1 = 10 - a;
		}
		else
		{
			int new_dp0 = a + min(dp0, dp1 + 1);
			int new_dp1 = min(10 - a + dp0, 10 - (a +1) + dp1);

			dp0 = new_dp0;
			dp1 = new_dp1;
		}
		
		/*a += prev;
		const auto back_pay = (10 - a) % 10;
		if (a <= back_pay)
		{
			res += a;
			prev = 0;
		}
		else
		{
			res += back_pay;
			prev = 1;
		}*/
	}
	dp1++;
	//res += prev;

	cout << min(dp0, dp1);
}

