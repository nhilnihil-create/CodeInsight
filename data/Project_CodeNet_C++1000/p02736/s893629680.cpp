#include<bits/stdc++.h>
using namespace std;
template<typename T>inline T read(){
	T x=0,f=0;char c=getchar();
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-48,c=getchar();
	return f?-x:x;
}
namespace run{
	const int N=1e6+9;
	inline bool Lucas(int n,int m){
		if(m==0) return 1;
		return (m&1)<=(n&1) && Lucas(n/2,m/2);
	}
	int n,a[N];
	inline bool check(){
		int ret=0;
		for(int i=1;i<=n;i++)
			if(Lucas(n-1,i-1) && a[i]&1) ret^=1;
		return ret;
	}
	int main(){
		n=read<int>();
		for(int i=1;i<=n;i++){
			char c;cin>>c;
			a[i]=c-'0';
		}
		for(int i=1;i<n;i++) a[i]=abs(a[i]-a[i+1]);
		n--;

		if(check()) puts("1"),exit(0);
		else{
			for(int i=1;i<=n;i++)
				if(a[i]&1) puts("0"),exit(0);
			for(int i=1;i<=n;i++) a[i]>>=1;
			if(check()) puts("2");
			else puts("0");
		}
		return 0;
	}
}
int main(){
#ifdef my
	freopen(".in","r",stdin);
	freopen(".out","w",stdout);
#endif
	return run::main();
}