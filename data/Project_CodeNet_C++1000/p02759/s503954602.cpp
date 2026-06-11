#include <cstdio>
using namespace std;
int main(){
	int n;scanf("%d",&n);
	if((n&1) == 1)printf("%d",n/2+1);
	else printf("%d",n/2);
	return 0;
	}
