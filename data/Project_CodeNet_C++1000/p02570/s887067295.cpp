// abc177-A
#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>
#include <map>

using namespace std;
typedef double dou;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	dou a,b,c;
	cin>>a>>b>>c;
	if (b>=a/c)
	cout<<"Yes"<<endl;
	else 
	cout<<"No"<<endl;
	return 0;	
}