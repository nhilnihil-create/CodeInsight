#include <cstdio>
#include <string>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;

int n,tmp;
int main() {
	scanf("%d",&n),tmp=1;
	for(int i=1;i<=23;++i,tmp<<=1) if(n==tmp) return puts("No"),0;
    puts("Yes");
	for(int i=3;i<=n;i+=2)
		printf("%d %d\n",i,1),
		printf("%d %d\n",i-1,1),
		printf("%d %d\n",i,i-1+n),
		printf("%d %d\n",i-1,i+n);
	printf("%d %d\n",1+n,3+n);
	if(!(n&1)) {
		for(int i=2;i<n;++i) {
			int tmp=i^n^1;
			if(1<tmp&&tmp<n)
				printf("%d %d\n",n,i),
				printf("%d %d\n",n+n,tmp),
				exit(0);
		}
	}
	return 0;
}