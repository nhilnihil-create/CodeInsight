#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
#define N 100010
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,a[N],ans;
vector<pair<int,int> > op;
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	if(a[1]>=0){
		ans=a[1];
		for(int i=2;i<n;++i){
			op.emplace_back(ans,a[i]);
			ans-=a[i];
		}
		op.emplace_back(a[n],ans);
		ans=a[n]-ans;
	}
	else if(a[n]<=0){
		ans=a[n];
		for(int i=n-1;i>=1;--i){
			op.emplace_back(ans,a[i]);
			ans-=a[i];
		}
	}
	else{
		ans=a[1];
		int i;
		for(i=n;a[i-1]>=0;--i){
			op.emplace_back(ans,a[i]);
			ans-=a[i];
		}
		op.emplace_back(a[i],ans);
		ans=a[i]-ans;
		for(--i;i>1;--i){
			op.emplace_back(ans,a[i]);
			ans-=a[i];
		}
	} 
	printf("%d\n",ans);
	for(auto x:op){
		printf("%d %d\n",x.first,x.second);
	}
	return 0;
}

