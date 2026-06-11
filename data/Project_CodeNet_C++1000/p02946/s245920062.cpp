#include<bits/stdc++.h>
using namespace std;

int main()
{
	long long int x,k;
	cin>>k>>x;
	int i=x-k+1;
	int j=(k-1)*2+1;
	for(int k=0;k<j;k++) {cout<<i<<' ';i++;}
	cout<<endl;
return 0;
}