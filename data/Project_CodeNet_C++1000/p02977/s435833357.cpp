#include<iostream>
using namespace std;
int N;
main()
{
	cin>>N;
	if(__builtin_popcount(N)==1)
	{
		cout<<"No"<<endl;
		return 0;
	}
	cout<<"Yes"<<endl;
	if(N%2==1)
	{
		for(int i=2;i<=N;i+=2)
		{
			cout<<"1 "<<i<<endl;
			cout<<i<<" "<<i+1<<endl;
			cout<<"1 "<<N+i+1<<endl;
			cout<<N+i+1<<" "<<N+i<<endl;
			if(i==2)
			{
				cout<<i+1<<" "<<N+1<<endl;
			}
		}
	}
	else
	{
		for(int i=2;i<=N-3;i+=2)
		{
			cout<<"1 "<<i<<endl;
			cout<<i<<" "<<i+1<<endl;
			cout<<"1 "<<N+i+1<<endl;
			cout<<N+i+1<<" "<<N+i<<endl;
			if(i==2)
			{
				cout<<i+1<<" "<<N+1<<endl;
			}
		}
		int a=N-2,b=N-1,c=N;
		cout<<(a^c)<<" "<<a<<endl;
		cout<<a<<" "<<c<<endl;
		cout<<(a^c)<<" "<<N+c<<endl;
		cout<<N+c<<" "<<N+a<<endl;
		cout<<a<<" "<<b<<endl;
		cout<<(a^c^1)<<" "<<N+b<<endl;
	}
}
