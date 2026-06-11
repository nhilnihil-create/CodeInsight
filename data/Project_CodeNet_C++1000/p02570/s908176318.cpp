#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ll long long 
#define N 100005
typedef std::pair<int,int> pii;


int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	int d,t,s;
	std::cin>>d>>t>>s;
	if((double)d/t<=s) puts("Yes");
	else puts("No");
	return 0;
}