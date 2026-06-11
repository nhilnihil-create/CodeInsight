#include<cstdio>
#include<algorithm>
using namespace std;
int main(void)
{
	double f=0;
	int a,b,i,c=0,x[1000];
	scanf("%d %d",&a,&b);
	for(i=0;i<a;i++){
		scanf("%d",&x[i]);
		f=f+x[i];
	}
	for(i=0;i<a;i++){
		if(x[i]>=f/4/b){
			c++;
		}
	}
	if(c>=b){
		printf("Yes\n");
	}
	else printf("No\n");
	return 0;
}