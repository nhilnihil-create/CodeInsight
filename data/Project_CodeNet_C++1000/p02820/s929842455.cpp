#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=1e5+4;
int n,K;
int R,S,P;
char T[N];
inline int read() {
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
int ans;
char sta[N];
bool mk[N];
inline int calc(int p) {
	memset(mk,false,sizeof(mk));
	int ret=0,tot=0;
	for (register int i=p;i<=n;i+=K) {
		sta[++tot]=T[i];
	}
	for (register int i=1;i<=tot;++i) {
		if (sta[i]==sta[i-1]&&mk[i-1]) continue;
		if (sta[i]=='r') ret+=P;
		else if (sta[i]=='s') ret+=R;
		else ret+=S;
		mk[i]=true;
	}
	return ret;
}
int main() {
//	freopen("in.txt","r",stdin);
	n=read(),K=read();
	R=read(),S=read(),P=read();
	scanf("%s",T+1);
	for (register int s=1;s<=K;++s) {
		ans+=calc(s);
	}
	printf("%d\n",ans);
	return 0;
}