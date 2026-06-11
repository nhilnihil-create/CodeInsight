#include<bits/stdc++.h>
using namespace std;

template <typename T>
inline T read(){
	T x=0,f=1;char c=getchar();
	while(!isdigit(c)){	if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){x=(x<<3)+(x<<1)+(c-48);c=getchar();}
	return x*f;
}

#define lint long long int
#define ulint unsigned lint
#define readint read<int>()
#define readlint read<lint>()
const int inf=1e9+1e7,MAXN=3e5+1e1;

struct Node{
	int p,w;
}h[MAXN],s[MAXN];
int n,m,k,c,ans=1;

map <lint,int> Map;

bool Cmp(Node A,Node B){
	return A.w>B.w;
}

int main(void){

	// freopen("testdata.in","r",stdin);
	// freopen("testdata.out","w",stdout);

	scanf("%d%d%d",&n,&m,&k),c=max(n,m)+1;
	for(int i=1;i<=n;i++) h[i].p=i;
	for(int i=1;i<=m;i++) s[i].p=i;
	for(int i=1;i<=k;i++){
		lint l=readlint,r=readlint;
		++Map[l*(lint)(c)+r];
		++h[l].w,++s[r].w;
		// printf("%lld ",l*(lint)(c)+r);
	}
	// printf("\n");
	sort(h+1,h+n+1,Cmp),sort(s+1,s+m+1,Cmp);
	// for(int i=1;i<=n;i++) printf("(%d %d) ",h[i].p,h[i].w);printf("\n");
	// for(int i=1;i<=m;i++) printf("(%d %d) ",s[i].p,s[i].w);
	int maxn=h[1].w,maxm=s[1].w;
	for(int i=1;i<=n;i++){
		if(h[i].w!=maxn || (!ans)) break;
		for(int j=1;j<=m;j++){
			if(s[j].w!=maxm || (!ans)) break;
			// printf("%lld ",(lint)(h[i].p)*(lint)(c)+(lint)(s[j].p));
			if(!Map[(lint)(h[i].p)*(lint)(c)+(lint)(s[j].p)]) ans=0;
		}
	}
	printf("%d\n",maxn+maxm-ans);

	return 0;
}