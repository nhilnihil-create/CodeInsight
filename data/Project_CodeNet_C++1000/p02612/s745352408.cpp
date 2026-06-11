#include<bits/stdc++.h>
using namespace std;

int main()
{
	int n,b;
	cin>>n;
	if(n%1000!=0)
	b=n/1000+1;
	 else
	b=n/1000;
	
	b=b*1000;
	cout<<(b-n)<<endl;
	 
	return 0;
	
}