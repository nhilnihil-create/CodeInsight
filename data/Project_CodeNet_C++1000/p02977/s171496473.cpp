#include <bits/stdc++.h>
using namespace std;
#define lor(a,b,c) for(register int a=b;a<=c;++a)
#define ror(a,b,c) for(register int a=c;a>=b;--a)

const int MAXN=1e5+5;

int n;

int main(){
	scanf("%d",&n);
	if(n==3){
		puts("Yes"); lor(i,1,5) printf("%d %d\n",i,i+1); return 0;
	}
	int num=1,k=0;
	while(num<=n) num<<=1,++k; num>>=1; --k;
	if(num==n) return puts("No"),0;
	puts("Yes");
	lor(i,1,num-2) printf("%d %d\n",i,i+1);
	printf("%d %d\n",num-1,1+n);
	lor(i,1,num-2) printf("%d %d\n",i+n,i+1+n);
	printf("%d %d\n",num,1); printf("%d %d\n",num+1,num);
	printf("%d %d\n",num+1+n,1); printf("%d %d\n",num+1+n,num+n);
	lor(i,num+2,n) printf("%d %d\n%d %d\n",i,i-1+n,i+n,i-num);

	return 0;
}