#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	string s;
	cin>>s;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]+n>90)
		{
			cout<<char(64+(s[i]+n)%90);
		}
		else
		{
			cout<<char(s[i]+n);
		}
		
	}
	
	
 
}