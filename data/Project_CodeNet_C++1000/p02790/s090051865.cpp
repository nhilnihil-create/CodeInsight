#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int i,a,b,m,n;
	scanf("%d %d",&a,&b);
	if(a<=b){
		m=a;
		n=b;
	}
	else{
		m=b;
		n=a;
	}	
	for(i=0;i<n;i++){
		printf("%d",m);
	}
	return 0;
}