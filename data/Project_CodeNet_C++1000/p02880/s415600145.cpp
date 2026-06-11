#include<bits/stdc++.h>
using namespace std;
int main()
{
	set<int>se;
	for(int i=1;i<10;++i)
	{
		for(int j=1;j<10;++j) se.insert(i*j);
	}
	int a;
	cin>>a;
	if(se.count(a)) cout<<"Yes";
	else cout<<"No";
	return 0;
}