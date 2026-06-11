#include<iostream>
using namespace std;
int main()
{
	int n,d;
	cin>>n>>d;
	int k=2*d+1;
	int s; 
	if(n%k==0)
	s=n/k;
	else
	s=n/k+1;
	cout<<s;
} 