#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

int main() {
	int n;
	scanf("%d",&n);
	if ((n&-n)==n||n==1) {puts("No");return 0;}
	puts("Yes"); 
	printf("1 2\n2 3\n3 %d\n%d %d\n%d %d\n",n+1,n+1,n+2,n+2,n+3);
	for(int i=4;i<n;i+=2) printf("%d %d\n%d %d\n%d %d\n%d %d\n",i,i+1,i+1,n+1,n+1,i+n,i+n,i+n+1);
	if (!(n&1)) {
		fo(x,2,n-1) {
			if (x&1) continue;
			int y=x^1^n;
			if (y>0&&y<n) {
				printf("%d %d\n%d %d\n",x+n,n,y,n<<1);
				break;
			}
		}	
	}
	return 0;
}