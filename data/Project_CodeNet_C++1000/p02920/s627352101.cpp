#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	int n2=1; //n2<=262144
	for (int i = 0; i < n; ++i)
	{
		n2*=2;
	}
	int tmp;
	multiset<int> memo;
	for (int i = 0; i < n2; ++i)
	{
		cin>>tmp;
		tmp*=-1;
		memo.insert(tmp);
	}
	multiset<int> ok[n+2];
	ok[0].insert(*memo.begin());
	memo.erase(memo.begin());
	int now=0;
	while (memo.size()>0)
	{
		for (auto itr = ok[now].begin(); itr != ok[now].end(); ++itr)
		{
			auto make=memo.upper_bound(*itr);
			if (make==memo.end())
			{
				cout<<"No\n";
				return 0;
			}
			ok[now+1].insert(*itr);
			ok[now+1].insert(*make);
			memo.erase(make);
		}
		++now;
	}
	cout<<"Yes\n";
	return 0;
}