#include <bits/stdc++.h>

using namespace std;

multiset <int> s;
multiset <int> ::reverse_iterator rit;
multiset <int> ::iterator it;

vector <int> v;

main()
{
	int n;
	cin >> n;
	
	int p = (1 << n);
	
	for(int i = 1; i <= p; i++)
	{
		int x;
		cin >> x;
		
		s.insert(-x);
	}
	
	it = s.begin();
	v.push_back(*it);
	
	s.erase(it);
	
	for(int i = 1; i <= n; i++)
	{
		vector <int> t;
		
		for(auto j : v)
		{
			it = s.upper_bound(j);
			
			if(it == s.end())
			{
				cout << "No";
				return 0;
			}
			
			t.push_back(*it);
			s.erase(it);
		}
		
		for(auto j : t)
			v.push_back(j);
		
		sort(v.begin(), v.end());
	}
	
	cout << "Yes";
}