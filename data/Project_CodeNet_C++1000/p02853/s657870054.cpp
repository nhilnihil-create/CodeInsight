#include <bits/stdc++.h>
using namespace std;

int score(int a,int b)
{
	int total=0;
	if (a==1)  total+=300000; 
	if (b==1)  total+=300000; 
	if (a==2)  total+=200000; 
	if (b==2)  total+=200000; 
	if (a==3)  total+=100000; 
	if (b==3)  total+=100000;
	if (a==1&&b==1)  total+=400000;
	return total; 
}

int main()
{
	int n,m;
	cin>>n>>m;
	cout<<score(n,m)<<endl;
	return 0;
}