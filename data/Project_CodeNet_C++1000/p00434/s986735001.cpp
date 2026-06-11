#include<iostream>

using namespace std;

int main()
{
	bool b[31]={};
	for(int i=0,t;i<28;i++)	cin>>t,b[t]=true;
	for(int i=1;i<31;i++)	if(!b[i])	cout<<i<<endl;
	return 0;
}