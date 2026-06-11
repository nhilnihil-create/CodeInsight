#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
using namespace std;
int x,y,z;
int main()
{
	cin>>x>>y>>z;
	if(x==y && z!=x) cout<<"Yes";
	else if(x==z && y!=x) cout<<"Yes"; 
	else if(y==z && x!=y) cout<<"Yes";
	else cout<<"No";
	return 0;
}