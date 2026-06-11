#include<iostream>
#include<cstring>

using namespace std;
char s[1005];

int main(){
	cin>>s;
	int len=strlen(s);
	if(s[len-1]=='s') s[len]='e',s[len+1]='s';
	else s[len]='s';
	cout<<s<<endl;
	return 0;	
}