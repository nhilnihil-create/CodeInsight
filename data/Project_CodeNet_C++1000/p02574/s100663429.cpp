#include <bits/stdc++.h>
using namespace std;

/*
提出前に確認!
- setとmultisetを間違えない
*/

int gcd(int x, int y)
{
	if (y == 0) return (x);
	return (gcd(y, x % y));
}

int	main(void)
{
	int n;
	cin >> n;
	vector<int> a(n);
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a.begin(), a.end());
	//とりあえず先にsetwise判定
	int res = 0;
	for (int i = 0; i < n; i++) res = gcd(res, a[i]);
	bool is_setwise = (res == 1);
	//素数を全部求める
	vector<bool> is_prime(1e6 + 1, true);
	is_prime[0] = false; is_prime[1] = false;
	vector<int> prime_list;
	for (int i = 2; i * i <= 1e6; i++)
	{
		if (is_prime[i])
		{
			prime_list.push_back(i);
			for (int j = 2; (long long)j * i <= 1e6; j++) is_prime[j * i] = false;
		}
	}
	//78498
	map<int, bool> used_prime;
	//pairwise判定
	bool is_pairwise = true;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < prime_list.size(); j++)
		{
			if (a[i] == 1) break ;
			if (a[i] % prime_list[j] == 0)
			{
				if (used_prime[prime_list[j]] == true) is_pairwise = false;
				used_prime[prime_list[j]] = true;
				while (a[i] % prime_list[j] == 0) a[i] /= prime_list[j];
			}
		}	
		if (a[i] != 1)
		{
			if (used_prime[a[i]] == true) is_pairwise = false;
			used_prime[a[i]] = true;
		}
	}
	if (is_pairwise) cout << "pairwise coprime" << endl;
	else
	{
		if (is_setwise == true) cout << "setwise coprime" << endl;
		else cout << "not coprime" << endl;
	}
	return (0);
}
