#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	int n,a;
	int i,m=0,m1=0,x=0,y=0;
	scanf("%d",&n);
	for(i=0;i<n;i++){
		scanf("%d",&a);
		if(m<a){
			m1=m;
			m=a;
			x=i+1;
		}
		else if(m1<a){
			m1=a;
			y=i+1;
		}
	}
	for(i=1;i<=n;i++){
		if(i==x){
			printf("%d\n",m1);
		}
		else{
			printf("%d\n",m);
		}
	}
	return 0;
}