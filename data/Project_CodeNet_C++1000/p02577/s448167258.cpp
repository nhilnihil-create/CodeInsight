#include<bits/stdc++.h>

using namespace std;

#define ll long long
#define pii pair<int,int>

int main()
{
	
	string s;
	cin>>s;
	long long i =0;
	long long sum  =0;
	while(s[i] != '\0')
	{
		sum += (s[i]-'0');
		i++;
	}
	if(sum %9 == 0)
		cout<<"Yes"<<endl;
	else
		cout<<"No"<<endl;
}