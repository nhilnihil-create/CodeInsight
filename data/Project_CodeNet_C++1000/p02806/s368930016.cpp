#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
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
int n,t[55];
string s[55],X;
map<string,int> mp;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		cin>>s[i];
		t[i]=read();
	}
	for(int i=n;i>=1;--i){
		t[i]+=t[i+1];
		mp[s[i]]=t[i+1];
	}
	cin>>X;
	printf("%d\n",mp[X]);
	return 0;
}

