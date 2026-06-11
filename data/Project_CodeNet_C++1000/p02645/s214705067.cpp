#include<iostream>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
string s;
int main(){
	cin>>s;
	putchar(s[0]),putchar(s[1]),putchar(s[2]);
	return 0;
}
