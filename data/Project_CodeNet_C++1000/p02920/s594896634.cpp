#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define all(x) ((x).begin()),((x).end())
#define usecppio ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define int ll
int n;
multiset <int> s;
vector <int> v;

void print_set()
{
	printf("Current in set\n");
	for (auto it:s)
	{
		printf("%lld ",it);
	}
	printf("\n");

	printf("Current in vector\n");
	for (auto it:v)
	{
		printf("%lld ",it);
	}
	printf("\n");
}
int32_t main()
{
	usecppio
	cin >> n;
	int maxel = 0;
	int val = (1LL<<n);
	for (int i = 0; i<val; i++)
	{
		int c;
		cin >> c;
		s.insert(c);
		maxel = max(maxel, c);
	}
	s.insert(0);
	v.push_back(maxel);
	s.erase(s.lower_bound(maxel));
	bool flag = true;
	for (int i = 0; i<n; i++)
	{
		for (int j = 0; j<(1LL<<i); j++)
		{
			auto u = s.lower_bound(v[j]);
			u--;
			//printf("Erase %lld by %lld\n",*u,v[j]);
			if (*u == 0)
			{
				flag = false;
				break;
			}
			v.push_back(*u);
			s.erase(u);
		}
		sort(all(v));
		//print_set();
	}
	flag &= (s.size()==1);
	cout << (flag?"Yes":"No") << '\n';

}

