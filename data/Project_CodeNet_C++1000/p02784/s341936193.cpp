#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
	int a,b,c,d=0;
	cin>>a>>b;
	for(int i=1;i<=b;i++){
		cin>>c;
		d+=c;
	}
	if(d<a) cout<<"No";
	else cout<<"Yes";
	return 0; 
 } 