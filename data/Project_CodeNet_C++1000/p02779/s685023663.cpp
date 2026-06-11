#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
map<int,int> ma;
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a;
		cin>>a;
		ma[a]++;
		if(ma[a]>=2)
		{
			cout<<"NO"<<"\n";
			return 0;
		}
	}
	cout<<"YES"<<"\n";
	return 0;
}