#include<iostream>
using namespace std;
bool f(int p)
{
	if(p<2)return 0;
	for(int i=2;i*i<=p;i++)
	{
		if(p%i<1)return 0;
	}
	return 1;
}
int n;
main()
{
	while(cin>>n,n)
	{
		int cnt=0;
		for(int i=n;i++<n*2;)cnt+=f(i);
		cout<<cnt<<endl;
	}
}

