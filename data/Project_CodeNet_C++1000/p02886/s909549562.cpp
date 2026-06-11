#include <bits/stdc++.h> 
using namespace std; 
int main()
{
	int a,b[51],cnt=0;
	cin>>a;
	for (int i=0;i<a;i++)
		cin>>b[i];
	for (int i=0;i<a;i++)
		for (int n=i+1;n<a;n++)
			cnt+=b[i]*b[n];
	cout<<cnt;
	return 0;
}
