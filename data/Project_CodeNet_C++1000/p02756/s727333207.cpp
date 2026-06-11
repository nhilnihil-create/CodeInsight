#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=2002020;
char l[N],r[N],s[N];
int main()
{
	scanf("%s",s+1); int len=strlen(s+1);
	int aq; cin>>aq; int topl=0,topr=0,rev=0;
	while(aq--){
		int op; cin>>op;
		if(op==1)rev^=1;
		else{
			int F; cin>>F; char c; cin>>c;
			F=(F-1)^rev;
			if(F)r[++topr]=c;
			else l[++topl]=c;
		}
	}
	if(rev){
		for(int i=topr;i>=1;i--)cout<<r[i];
		for(int i=len;i>=1;i--)cout<<s[i];
		for(int i=1;i<=topl;i++)cout<<l[i];
	} else{
		for(int i=topl;i>=1;i--)cout<<l[i];
		for(int i=1;i<=len;i++)cout<<s[i];
		for(int i=1;i<=topr;i++)cout<<r[i];
	}
	return 0;
}