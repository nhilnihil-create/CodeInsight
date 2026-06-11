#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
	string s;
	cin>>s;
	
	int cnt=0,mx_cnt=0;
	
	for(int i=0;i<3;i++)
	{
		if(s[i]=='R')
			cnt++;
		else
			cnt=0;
		mx_cnt=max(mx_cnt,cnt);
	}
	cout<<mx_cnt;
}




