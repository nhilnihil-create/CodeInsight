#include<bits/stdc++.h>
#define fr(i,a,b) for(int i=(a);i<=(b);++i)
#define rf(i,a,b) for(int i=(a);i>=(b);--i)
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
using namespace std;
typedef long long ll;
template<typename T>
inline void read(T &x){
	char c=getchar();T fh=0;bool f=false;
	while(!isdigit(c))f|=(c=='-'),c=getchar();
	while(isdigit(c))fh=(fh<<1)+(fh<<3)+(c^48),c=getchar();
	x=f?-fh:fh;
	return;
}
char s[2005][2005];
int n,m,u[2005][2005],d[2005][2005],l[2005][2005],r[2005][2005],ans;
int main(){
    read(n),read(m);
	fr(i,1,n)cin>>s[i]+1;
	fr(i,1,n)fr(j,1,m)if(s[i][j]=='.'){
		u[i][j]=s[i-1][j]=='.'?u[i-1][j]+1:1;
		l[i][j]=s[i][j-1]=='.'?l[i][j-1]+1:1;
	} 
	rf(i,n,1)rf(j,m,1)if(s[i][j]=='.'){
		d[i][j]=s[i+1][j]=='.'?d[i+1][j]+1:1;
		r[i][j]=s[i][j+1]=='.'?r[i][j+1]+1:1;
	}
	fr(i,1,n)fr(j,1,m)ans=max(ans,u[i][j]+d[i][j]+l[i][j]+r[i][j]-3);
	printf("%d\n",ans);
	return 0;
}