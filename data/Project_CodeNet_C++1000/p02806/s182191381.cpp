#include <bits/stdc++.h>
using namespace std;

int main() {
	
	string s;
	map<string,int>mp;
	map<string,int>::iterator it;
	int n,x,y=0,count = 0;
	
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cin>>s>>x;
		count+=x;
		mp[s]=count;
	}
	cin>>s;
	it=mp.find(s);
	if(it!=mp.end()) y = it->second;
	cout<<count-y<<endl;
	return 0;
}