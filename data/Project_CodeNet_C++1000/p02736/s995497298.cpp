#include<cstdio>
typedef long long LL;
using namespace std;
const int N=1e6+5;
int n;
char s[N];
inline bool chk(){
	int u=0,v=0,w=0;
	for(int i=0;i<=n;++i){
		if(u==v)w=(w+s[i])&1;
		if(i<n)u+=__builtin_ctz(n-i),v+=__builtin_ctz(i+1);
	}
	return w;
}
int main(){
	scanf("%d%s",&n,s);
	if(!--n)putchar(*s);else{
		for(int i=0;i<=n;++i)--s[i];
		if(chk())putchar(49);else{
			bool ok=1;
			for(int i=0;i<=n;++i)
			if(s[i]==49)ok=0;else if(s[i]==50)--s[i];
			if(ok&&chk())putchar(50);else putchar(48);
		}
	}
	return 0;
}