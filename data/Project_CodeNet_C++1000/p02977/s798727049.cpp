#include <bits/stdc++.h>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while (ch<'0' || ch>'9'){
		if (ch=='-') f=-1;
		ch=getchar();
	}
	while (ch>='0' && ch<='9'){
		x=x*10+ch-'0';ch=getchar();
	}
	return x*f;
}
signed main(){
	int n=read();
	int k=1;while (k<n) k<<=1;
	if (k==n){
		printf("No\n");
		return 0;
	}	
	printf("Yes\n");
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,3);
	printf("%d %d\n",3,1);
	printf("%d %d\n",1,2);
	printf("%d %d\n",2,n+3);
	for (int j=4;j+1<=n;j+=2){
		int k=j+1;
		printf("%d %d\n",j,1);
		printf("%d %d\n",j,n+k);
		printf("%d %d\n",k,1);
		printf("%d %d\n",k,n+j);
	}	
	if (!(n&1)){
		for (int x=2;x<=n-1;++x){
			int y=n^x^1;
			if (y>=2&&y<=n-1) {
				printf("%d %d\n",n+n,x);
				printf("%d %d\n",n,y);
				break;
			}
		}
	}
	return 0;
}