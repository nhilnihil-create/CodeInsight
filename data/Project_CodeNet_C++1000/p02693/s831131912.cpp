#include<bits/stdc++.h>
using namespace std;
 

int main()
{
	int n,a,b;
	cin>>n>>a>>b;
	
	int k=a/n;
    if(a%n!=0) k++;    
	if(k*n<=b)
	{
		cout<<"OK\n";
	}
	else
	{
		cout<<"NG\n";
	}
}