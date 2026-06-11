#include<cstdio>
#include<functional>
#include<algorithm>
#include<iostream>
#include<cstring>
#include<string>
#include<cstdlib>
#include<cctype>
#define rep(i,a) for(int i=0;i<a;i++)
using namespace std;
int main(void)
{
	string s;
	getline(cin,s);
	rep(i,s.size()) {
		if(s[i]>='A' && s[i]<='Z') s[i]=tolower(s[i]);
		else s[i]=toupper(s[i]);
		cout<<s[i];
	}
	cout<<endl;
}