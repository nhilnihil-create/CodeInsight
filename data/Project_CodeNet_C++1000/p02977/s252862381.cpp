#include<bits/stdc++.h>
#define ll long long
#define ull unsigned ll
#define uint unsigned
#define pii pair<int,int>
#define pll pair<ll,ll>
#define PB push_back
#define fi first
#define se second
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define CLR(a,v) memset(a,v,sizeof(a));
#define CPY(a,b) memcpy(a,b,sizeof(a));
using namespace std;
int n,nn;
int main(){
	scanf("%d",&n);
	nn=n;
	if ((n&(-n))==n)
		return puts("No"),0;
	puts("Yes");
	printf("1 2\n2 3\n1 %d\n%d %d\n%d %d\n",n+3,n+3,n+2,n+2,n+1);
	if (nn%2==0){
		int d=1;
		for (;d*2<=n;d<<=1);
		printf("%d %d\n%d %d\n",n,d,n+(n-d+1),n+n);
		nn--;
	}
	for (;nn>3;nn-=2)
		printf("%d %d\n%d 1\n1 %d\n%d %d\n",nn,nn-1,nn-1,nn+n,nn+n,nn+n-1);
}