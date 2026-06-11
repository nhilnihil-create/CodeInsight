#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=x,i##end=y;i<=i##end;++i)
#define _rep(i,x,y) for(int i=x,i##end=y;i>=i##end;--i)
#define ll long long 
#define N 1000005
int n,a[N];
bool vis[N];
int s[N];
int main(){
	std::ios::sync_with_stdio(0);
	std::cin.tie(0),std::cout.tie(0);
	std::cin>>n;
	int mx=0;
	rep(i,1,n){
		std::cin>>a[i];
		++s[a[i]];
		mx=std::max(mx,a[i]);
	}
	int g=a[1];
	rep(i,2,n) g=std::__gcd(g,a[i]);
	bool setwise=g==1;
	if(!setwise) return std::cout<<"not coprime\n",0;
	bool pairwise=1;
	rep(i,2,mx){
		if(vis[i]) continue;
		int cnt=0;
		for(int j=i;j<=mx;j+=i){
			vis[j]=1;
			cnt+=s[j];
		}
		if(cnt>1){pairwise=0; break;}
	}
	
	if(pairwise) std::cout<<"pairwise coprime\n";
	else std::cout<<"setwise coprime\n";
	return 0;
}