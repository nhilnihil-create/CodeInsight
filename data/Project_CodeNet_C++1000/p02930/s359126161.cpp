#include <bits/stdc++.h>

using namespace std;

typedef pair<int,int> pii;
typedef long long ll;

template<class T>void byebye(T _rpl) {
	cout<<_rpl<<endl;
	exit(0);
}
int nextint() {
	int x;
	scanf("%d",&x);
	return x;
}
ll nextll() {
	ll x;
	scanf("%lld",&x);
	return x;
}

int read() {
	int f=1,ret=0;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		ret=ret*10+(c-'0');
		c=getchar();
	}
	return ret*f;
}

int p[505][505];
int col[505];
int n,cnt;
void construct(int l,int r,int x) {
	if(l>=r||l+1==r)return;
	int mid=l+r>>1;
	for(int i=l;i<mid;++i){
		for(int j=mid;j<r;++j)	p[i][j]=x;
	}
	construct(l,mid,x+1);
	construct(mid,r,x+1);
}

int main() {
	n=read();
	construct(0,n,1);
	for(int i=0;i<n;++i){
		for(int j=i+1;j<n;++j){
			printf("%d ",p[i][j]);
		}
		puts("");
	}
	return 0;
}
