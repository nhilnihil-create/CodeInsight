#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<sstream>
using namespace std;
int x;
string s;
int main()
{
	cin>>x;
	cin>>s;
	int sum=0;
	for(int i=1;i<s.size()-1;i++)
	{
		if(s[i]=='B'&&s[i-1]=='A'&&s[i+1]=='C')
			sum++;	
	}
	cout<<sum;
}
