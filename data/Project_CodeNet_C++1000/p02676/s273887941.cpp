#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	string b;
	cin>>n>>b;
	int k=b.length();
	if(n>=k)
	{
		cout<<b<<endl;
	}
	else
	{
		for(int i=0;i<n;i++)
		{
			cout<<b[i];
		}
		cout<<"..."<<endl;
	}
	
}
