#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

vector <int> v;
char s[maxn];

int main()
{
	int n=read(); scanf("%s",s+1);
	for(int i=1;i<n;i++) v.push_back(abs(s[i]-s[i+1]));
	int f=0,p=v.size()-1,ans=0;
	for(int i=0;i<v.size();i++) if(v[i]==1) f=1;
	for(int i=0;i<v.size();i++) if((p&i)==i) ans+=v[i]; ans%=2;
	if(ans==0)
	{
		if(f==1) puts("0");
		else
		{
			int c1=0,c2=0; ans=0;
			for(int i=0;i<v.size();i++) v[i]/=2;
			for(int i=0;i<v.size();i++) if((p&i)==i) ans+=v[i]; ans%=2;
			if(ans==0) puts("0"); else puts("2");
		}
	}
	else puts("1");
	return 0;
}