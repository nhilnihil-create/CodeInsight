#include <bits/stdc++.h>

using namespace std;

#define int long long

const int DIM = 2e5 + 7;

int v[DIM];

main()
{
	int n;
	cin >> n;
	
	int total = 0;
	
	for(int i = 1; i <= n; i++)
	{
		cin >> v[i];
		total ^= v[i];
	}
	
	for(int i = 1; i <= n; i++)
		v[i] = ((v[i] | total) ^ total);
	
	vector <int> bases;
	
	sort(v + 1, v + 1 + n);
	
	for(int i = n; i >= 1; i--)
	{
		for(auto j : bases)
			v[i] = min(v[i], v[i] ^ j);
		
		if(v[i])
			bases.push_back(v[i]);
	}
	
	int s = 0;
	
	for(auto i : bases)
		s = max(s, s ^ i);
	
	cout << 2 * s + total;
}