#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<set>
#include<math.h>
#include<map>
using namespace std;
using ll = long long;
using ull = unsigned long long;
#define rep(i,n) for(ll i=0;i<n;i++)


int main()
{
	map<string, ll> dict;
	ll n;
	cin >> n;
	string s;
	for (ll i = 0; i < n; i++)
	{
		cin >> s;
		dict[s]++;
	}
	
	typename map<string, ll> ::iterator it = begin(dict);
	ll max = 0;
	while (it != end(dict))
	{
		if (max < it->second)
		{
			max = it->second;
		}
		it++;
	}
	typename map<string, ll> ::iterator itr = begin(dict);
	while (itr != end(dict))
	{
		if (itr->second == max)
		{
			cout << itr->first << "\n";
		}
		itr++;
	}

	return 0;
}