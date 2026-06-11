#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 1000100
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
int n,a[N],b[N],c[N],tmp[N];
char s[N];
inline int C(int n,int m){
	if(n==m||!m)return 1;
	if(n<m)return 0;
	return C(n&1,m&1)*C(n>>1,m>>1);
}
int Solve(int *p){
	int ans=0;
	for(int i=1;i<=n;++i){
		if(tmp[i]){
			ans^=p[i];
		}
	}
	return ans;
}
int main(){
	n=read();
	scanf("%s",s+1);
	bool ok=0;
	for(int i=1;i<=n;++i){
		a[i]=s[i]-'0'-1;
		if(a[i]==1)ok=1;
		b[i]=(a[i]&1);
		c[i]=(a[i]>>1);
	}
	for(int i=1;i<=n;++i){
		tmp[i]=C(n-1,i-1);
	}
	if(!ok){
		printf("%d\n",Solve(c)<<1);
	}
	else{
		printf("%d\n",Solve(b));
	}
	return 0;
}
