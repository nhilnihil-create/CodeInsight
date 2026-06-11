#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+5;
struct edge{
	int nxt,to;
}e[N];
int head[N],cnt,in[N];
void add(int x,int y){
	in[y]++;
	e[++cnt].to=y; e[cnt].nxt=head[x]; head[x]=cnt;
} 
int ans[N];queue<int> q;
char S[N];
signed main(){
	cin>>S+1;
	int len=strlen(S+1);
	for(int i=1;i<=len;++i){
		if(S[i]=='<') add(i,i+1);
		else add(i+1,i);
	}
	int n=len+1;
	for(int i=1;i<=n;++i)
		if(!in[i]) q.push(i);
	while(!q.empty()){
		int u=q.front();q.pop();
		for(int i=head[u];i;i=e[i].nxt){
			int v=e[i].to;
			in[v]--;ans[v]=max(ans[u]+1,ans[v]);
			if(!in[v]) q.push(v);
		}
	}
	int sum=0;
	for(int i=1;i<=n;++i)
		sum+=ans[i];
	cout<<sum;
	return 0;
}