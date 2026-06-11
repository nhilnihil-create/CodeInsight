#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ll long long 
#define N 100005
typedef std::pair<int,int> pii;
int lens,lent;
char s[N],t[N];
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>s+1>>t+1;
	lens=strlen(s+1);
	lent=strlen(t+1);
	int ret=2e9;
	rep(i,1,lens-lent+1){
		int cnt=0;
		rep(j,i,i+lent-1)
			cnt+=s[j]!=t[j-i+1];
		ret=std::min(ret,cnt);
	}
	std::cout<<ret<<'\n';
	return 0;
}