#include<bits/stdc++.h>
#define ll long long
using namespace std;
char s[200020];
int main()
{
	int n,a,b,c,d,i;cin>>n>>a>>b>>c>>d;cin>>s+1;
	for (i=b;i<d;i++){
		if (s[i+1]=='#' && s[i]=='#') {puts("No");exit(0);}
	}
	for (i=a;i<c;i++){
		if (s[i+1]=='#' && s[i]=='#') {puts("No");exit(0);}
	}
		if (d>c) puts("Yes");
		else{
			for (i=b;i<=d;i++) if (s[i-1]==s[i] && s[i]==s[i+1] && s[i]=='.') {puts("Yes");exit(0);}
			puts("No");
		}
}