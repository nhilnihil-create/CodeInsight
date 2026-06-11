#include<bits/stdc++.h>
using namespace std;
int main()
{
	long long a;
	string b;
	cin>>a>>b;
	int ans;
	ans+=(b[0]-'0')*100;
	ans+=(b[2]-'0')*10;
	ans+=(b[3]-'0');
	long long d=a*ans/100; 
	cout<<d<<endl;
}