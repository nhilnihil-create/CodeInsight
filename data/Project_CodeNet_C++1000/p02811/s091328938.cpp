#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
	int k,x;
	cin>>k>>x;
	int ans=k*500;
	if(ans>=x)
	{
		cout<<"Yes"<<"\n";
	}
	else cout<<"No"<<"\n";
	return 0;
}