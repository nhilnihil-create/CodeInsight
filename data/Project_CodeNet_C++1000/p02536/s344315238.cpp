#include<bits/stdc++.h>

using namespace std;

typedef long long ll;

inline ll read(){
    char ch=getchar();ll x=0,f=1;
    while(ch<'0' || ch>'9') {
       if(ch=='-') f=-1;
      	  ch=getchar();
    }
    while(ch<='9' && ch>='0') {
       x=x*10+ch-'0';
       ch=getchar();
    }
    return x*f;
}

int f[2020200];
int fa[2020020];

int find(int x){
	if(x==fa[x]) return x;
	else return fa[x]=find(fa[x]);
}

void merge(int x,int y){
	int fx=find(x),fy=find(y);
	if(fx==fy) return;
	fa[fx]=fy;
}

int main(){
	int n=read();
	int m=read();
	for(int i=1;i<=n;i++){
		fa[i]=i;
	}
	for(int i=1;i<=m;i++){
		int x=read(),y=read();
		merge(x,y);
	}
	int sum=0;
	for(int i=1;i<=n;i++){
		if(f[find(i)]==0){
			f[find(i)]=1;
			sum++;
		}
	}
	printf("%d\n",sum-1);
	return 0;
}
