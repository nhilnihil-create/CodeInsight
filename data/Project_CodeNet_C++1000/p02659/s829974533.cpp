#include<iostream>
#include<string.h>
#include <algorithm>
#include <cstring>
#include <math.h>
#include <map>
using namespace std;

int main()
{
	long long a;
	char s[4];
	cin>>a>>s;
	int bb =(s[0]-'0')*100 +(s[2]-'0')*10+(s[3]-'0');
	long long ans =bb*a/100;
	cout<<ans<<endl;
	
	return 0;
}