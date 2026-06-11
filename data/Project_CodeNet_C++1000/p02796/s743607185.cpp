#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int inf=0x3f3f3f3f;
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
int n,ans;
pair<int,int> a[N];
int main(){
	n=read();
	for(int i=1;i<=n;++i){
		int x=read(),L=read();
		a[i]=make_pair(x+L,x-L);
	}
	sort(a+1,a+n+1);
	int now=-inf;
	for(int i=1;i<=n;++i){
		if(a[i].second>=now){
			++ans;
			now=a[i].first;
		}
	}
	printf("%d\n",ans);
	return 0;
}

