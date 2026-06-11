#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#include <bits/stdc++.h>
using namespace std;
template<class t> inline t read(t &x){
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}

const int N=2e5+5;
char s[N];
int n,ans;

signed main(){
	scanf("%s",s+1);n=strlen(s+1);
	for(int i=2,last=1;i<=n;i++){
		ans++;
		if(last==1){
			if(s[i]==s[i-1]){
				if(i<n) i++,last=2;
				else ans--;
			}
		}
		else last=1;
	}
	write(ans+1);
}