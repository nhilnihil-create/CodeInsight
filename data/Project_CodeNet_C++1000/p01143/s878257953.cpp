#include<iostream>
using namespace std;
int n,m,p;
main()
{
	while(cin>>n>>m>>p,n)
	{
		int cnt=0,x[100];
		for(int i=0;i<n;i++)
		{
			cin>>x[i];
			cnt+=x[i];
		}
		cout<<(x[m-1]?cnt*(100-p)/x[m-1]:0)<<endl;
	}
}
