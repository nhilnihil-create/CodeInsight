#include<bits/stdc++.h>
#define ll long long
#define F first
#define S second
#define scn(n) scanf("%d",&n)
using namespace std;

int main() {
	
	string s,t;
	cin>>s;
	cin>>t;
	
	int cnt=0;
	for(int i=0;i<s.size();i++)
	{
	    if(s[i]==t[i])
	    continue;
	    else
	    cnt++;
	}
	cout<<cnt;
	return 0;
}