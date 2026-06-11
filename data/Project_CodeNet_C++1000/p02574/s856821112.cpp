#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
#include <unordered_set>
#include <cmath>
#include <algorithm>
#include <climits>
#include <iomanip>
#define endl "\n"
#define debug(x) cout << #x << " : " << x << endl;
#define debug2(x, y) cout << #x << " : " << x  << ", " << #y << " : " << y << endl;
#define FASTIO ios_base::sync_with_stdio(false),cin.tie(0);
typedef long long ll;
using namespace std;

const int maxn = 1e6 + 5;
int spf[maxn];
int gcd(int a, int b)
{
	if(b == 0)
		return a;
	return gcd(b, a % b);
}

void sieve()
{
	for(int i = 1; i <= 1e6; i ++)
	{
		if(i % 2 == 0)
			spf[i] = 2;
		else
			spf[i] = i;
	}

	for(int i = 3; i * i <= 1e6; i ++)
	{
		if(spf[i] == i)
		{
			for(int j = i; i * j <= 1e6; j ++)
			{
				if(spf[i * j] == i * j)
					spf[i * j] = i;
			}
		}
	}
}

int main()
{
	FASTIO

	sieve();
	int n;
	cin >> n;

	vector <int> v(n);
	for(int i = 0; i < n; i ++)
	{
		cin >> v[i];
	}	

	int gcdVal = 0;
	int flag = 0; // Array is pairwise coprime
	for(int i = 0; i < n; i ++)
	{
		gcdVal = gcd(gcdVal, v[i]);
	}

	map <int, bool> mp;
	set <int> primes;
	for(int i = 0; i < n; i ++)
	{
		int val = v[i];
		primes.clear();
		while(val != 1)
		{
			primes.insert(spf[val]);
			val = val / spf[val];
		}

		for(auto it = primes.begin(); it != primes.end(); it ++)
		{
			if(mp.find(*it) != mp.end())
			{
				flag = 1;
				break;
			}
			mp[*it] = true;
		}

		if(flag == 1)
			break;
	}

	if(flag == 0)
	{
		cout << "pairwise coprime" << endl;
	}
	else if(gcdVal == 1)
		cout << "setwise coprime" << endl;
	else 
		cout << "not coprime" << endl;


}	