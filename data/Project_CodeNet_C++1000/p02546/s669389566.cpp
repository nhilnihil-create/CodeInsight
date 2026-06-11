#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;

int main()
{
	string s;cin>>s;
	if(s[s.size()-1]=='s') s+="es";
	else s+="s";
	cout<<s;
	return 0;	
} 