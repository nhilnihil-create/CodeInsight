#include <bits/stdc++.h>
using namespace std;

int main()
{
	string s;
  	cin>>s;
  	int a=s.size();
  	if(s[a]=='s'||s[a]=='x'||s[a]=='h'&&s[a-1]=='c'||s[a-1]=='s'){
  		cout<<s<<"es";	
	}
	else{
		cout<<s<<"s";
	}
	return 0;
}