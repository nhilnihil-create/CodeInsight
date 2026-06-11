#include <iostream>
using namespace std;
int main() 
{
	int h,n0,t=0;
	cin>>h>>n0;
	const int n =n0;
	int a[n];
	for(int i=0;i<n;i++)
	{
		cin>>a[i];
		t = t+a[i];
	}
	if(t>=h)
	{
		cout<<"Yes";
	}
	else
	{
		cout<<"No";	
	}
	
	return 0;
}