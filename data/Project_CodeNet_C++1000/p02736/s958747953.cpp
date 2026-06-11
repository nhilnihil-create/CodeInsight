#include<bits/stdc++.h>
#define ll long long
#define re register
#define cs const

using std::cerr;
using std::cout;

cs int N=1e6+7;

int n,c1;
int ans;
char s[N];

void Main(){
	scanf("%d%s",&n,s+1);
	for(int re i=1;i<=n;++i)s[i]-=49;
	for(int re i=1;i<=n;++i)
		if(s[i]==1){
			c1=true;
			ans^=((n-1)^(i-1)^(n-i))==0;
		}
	if(ans)cout<<1<<"\n";
	else if(c1)cout<<0<<"\n";
	else {
		ans=0;
		for(int re i=1;i<=n;++i)
			if(s[i]==2)ans^=((n-1)^(i-1)^(n-i))==0;
		cout<<(ans*2)<<"\n";
	}
}

inline void file(){
#ifdef zxyoi
	freopen("B.in","r",stdin);
#endif
}signed main(){file();Main();return 0;}