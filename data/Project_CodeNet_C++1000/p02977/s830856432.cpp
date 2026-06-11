#include<set>
#include<map>
#include<stack>
#include<cmath>
#include<queue>
#include<cstdio>
#include<vector>
#include<climits>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define LL long long
int read(){
	int f=1,x=0;char c=getchar();
    while(c<'0'||'9'<c){if(c=='-')f=-1;c=getchar();}
    while('0'<=c&&c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
    return f*x;
}
#define MAXN 100000
#define INF 0x3f3f3f3f
int main(){
	//freopen("tree.in","r",stdin);
	//freopen("tree.out","w",stdout);
	int n=read();
	if(n<3||log2(n)==int(log2(n))){
		puts("No");
		return 0;
	}
	if(n%2!=0){
		puts("Yes");
		for(int i=2;i<=n;i+=2)
			printf("%d %d\n%d %d\n%d %d\n%d %d\n",1,i+n,1,i+1,i+n,i+1+n,i,i+1);
		printf("%d %d\n",2,n+1);
	}
	else{
		puts("Yes");
		for(int i=2;i<n;i+=2)
			printf("%d %d\n%d %d\n%d %d\n%d %d\n",1,i+n,1,i+1,i+n,i+1+n,i,i+1);
		printf("%d %d\n",2,n+1);
		int a=(n&-n),b=2*n-a;a++;
		printf("%d %d\n%d %d\n",n,a,2*n,b);
	}
    return 0;
}
