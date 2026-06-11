#include<iostream>
using namespace std;
main()
{
	int n;
	cin>>n;
	int k=(n-n%500)/500;
	int m=(n%500)/5;
	int p=1000*k+5*m;
	cout<<p<<"\n";
}
