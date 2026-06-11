#include <bits/stdc++.h>
using namespace std;

int main()
{
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int ara[3];
	for (int i = 0; i < 3; ++i)
	{
		cin>>ara[i];
	}
	sort(ara, ara+3, greater<int>());
	if(ara[0] == ara[1] && ara[0] != ara[2])
		cout<<"Yes"<<endl;
	else if(ara[1] == ara[2] && ara[2] != ara[0])
		cout<<"Yes"<<endl;
	else if(ara[0] == ara[2] && ara[0] != ara[1])
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;

	return 0;
}