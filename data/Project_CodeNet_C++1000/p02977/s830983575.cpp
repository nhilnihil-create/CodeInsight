#include<bits/stdc++.h>
#define For(i,j,k) for (int i=(int)(j);i<=(int)(k);i++)
#define Rep(i,j,k) for (int i=(int)(j);i>=(int)(k);i--)
#define pii pair<int,int>
#define fi first
#define se second
#define PB push_back
using namespace std;
int n;
int main(){
	scanf("%d",&n);
	if ((n&(-n))==n) return puts("No"),0;
	puts("Yes");
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for (int j=4;j+1<=n;j+=2) printf("%d %d\n%d %d\n%d %d\n%d %d\n",j,j+1,j+1,n+1,n+1,n+j,n+j,n+j+1);
	if (n%2==0){
		int id1=1;
		for (;id1*2<=n;id1*=2);
		printf("%d %d\n%d %d\n",n,n+id1,n+1-id1,n+n);
	}
}
/*
46
57
1-2-3-1-2-3
  46
  57
*/