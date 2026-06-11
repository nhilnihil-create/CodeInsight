#include<bits/stdc++.h>

#define mp make_pair
#define fi first
#define se second

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;

int readint(){
	int x=0,f=1; char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}

int n;

int main(){
	n=readint();
	if((n&(n-1))==0) return printf("No\n"),0;
	printf("Yes\n");
	if(n&1){
		for(int i=2;i<=n;i+=2){
			printf("%d %d\n",i,i+1);
			printf("%d %d\n",i+1,1);
			printf("%d %d\n",1,i+n);
			printf("%d %d\n",i+n,i+n+1);
		}
		printf("%d %d\n",n+3,n+1);
		return 0;
	}
	for(int i=2;i<=n-1;i+=2){
		printf("%d %d\n",i,i+1);
		printf("%d %d\n",i+1,1);
		printf("%d %d\n",1,i+n);
		printf("%d %d\n",i+n,i+n+1);
	}
	printf("%d %d\n",n+3,n+1);
	int tmp=n&(-n);
	printf("%d %d\n",n,tmp^1);
	printf("%d %d\n",(n^tmp)+n,n+n);
	return 0;
}