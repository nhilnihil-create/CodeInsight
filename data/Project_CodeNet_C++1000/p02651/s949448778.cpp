#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T x=0,f=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
#define int long long
namespace run{
	const int N=209;
	namespace linebasis{
		int a[69];
		inline void insert(int x){
			for(int i=63;~i;i--)
				if((x>>i)&1){
					if(!a[i]) return a[i]=x,void();
					else x^=a[i];
				}
		}
		inline bool check(int x){
			for(int i=63;~i;i--)
				if((x>>i)&1) x^=a[i];
			return !x;
		}
	}using namespace linebasis;

	int n,A[N];char s[N];
	int main(){
		int T=read<int>();
		while(T--){
			n=read<int>();
			for(int i=1;i<=n;i++) A[i]=read<int>();
			cin>>s+1;

			memset(a,0,sizeof a);
			int peg=0;
			for(int i=n;i>=1;i--)
				if(s[i]=='1' && !check(A[i])) peg=1;
				else insert(A[i]);

			if(!peg) puts("0");
			else puts("1");
		}
		return 0;
	}
}
#undef int
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}