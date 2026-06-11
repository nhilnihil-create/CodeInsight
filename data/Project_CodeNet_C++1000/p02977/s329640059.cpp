#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=2008;
int read(){
    int f=1,g=0;char ch=getchar();
    for (;!isdigit(ch);ch=getchar()) if (ch=='-') f=-1;
    for (;isdigit(ch);ch=getchar()) g=g*10+ch-'0';
    return f*g;
}
int n;
int main(){
	n=read();
	if (n==(n&(-n))){puts("No");return 0;}
	puts("Yes");
	for (int i=2;i<n;i+=2)
		printf("1 %d\n1 %d\n",i,i+1);
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,3);
	printf("%d %d\n",2,n+3);
	for (int i=4;i<n;i+=2){
		printf("%d %d\n",i,n+i+1);
		printf("%d %d\n",n+i,i+1);
	}
	if (!(n&1))
	for (int i=2;i<n;i++){
		int j=n^1^i;
		if ((j>1)&&(j<n)){
			printf("%d %d\n",i,n);
			printf("%d %d\n",j,n+n);
			return 0;
		}
	}
	return 0;
}
