#include <bits/stdc++.h>
using namespace std;
multiset<int,greater<int> > s,s2;
int main()
{
	int p;
	scanf("%d",&p);
	int n=(1<<p);
	for (int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		s.insert(a);
	}
	s2.insert(*s.begin());
	s.erase(s.begin());
	for (int i=0;i<p;i++)
	{
		vector<int> in;
		for (int j:s2)
		{
			auto it=s.upper_bound(j);
			if (it==s.end())
			{
				printf("No");
				return 0;
			}
			in.push_back(*it);
			s.erase(it);
		}
		for (int j:in)
		s2.insert(j);
	}
	printf("Yes");
}