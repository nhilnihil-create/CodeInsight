#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
using namespace std;

const int mn=2005;
bool s[mn][mn];
int u[mn][mn],d[mn][mn],l[mn][mn],r[mn][mn];

int main()
{
	int n,m,ans=0;
	scanf("%d%d",&n,&m);
	char c;
	FOR(i,1,n) FOR(j,1,m) {c=getchar();while(c!='.'&&c!='#') c=getchar();s[i][j]=(c=='.');}
	FOR(i,1,n) FOR(j,1,m) {
		if(!s[i][j]) continue;
		if(s[i][j-1]) l[i][j]=l[i][j-1]+1,r[i][j]=r[i][j-1]-1;
		else {l[i][j]=0;FOR(k,j+1,m) {if(!s[i][k]) break;r[i][j]++;}}
		if(s[i-1][j]) u[i][j]=u[i-1][j]+1,d[i][j]=d[i-1][j]-1;
		else {u[i][j]=0;FOR(k,i+1,n) {if(!s[k][j]) break;d[i][j]++;}}
		ans=max(ans,l[i][j]+r[i][j]+u[i][j]+d[i][j]+1);
	}
	cout<<ans;
}