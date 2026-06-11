#include<bits/stdc++.h>
using namespace std;
vector<int>v1,v2;
int main()
{
	int n;cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y;cin>>x>>y;
		v1.push_back(x+y);
		v2.push_back(x-y);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	cout<<max(v1.back()-v1.front(),v2.back()-v2.front())<<endl;
}