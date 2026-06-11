#include<stdio.h>
#include<algorithm>
using namespace std;
int main()
{
	int a,i;
	scanf("%d",&a);
	int x[a],y[a],z[a];
	for(i=0;i<a;i++){
		scanf("%d",&x[i]);
		y[i]=x[i];
	}
	sort(y,y+a);
	for(i=0;i<a;i++){
		if(x[i]==y[a-1]){
			printf("%d\n",y[a-2]);
		}
		else if(x[i]<=y[a-1]){
			printf("%d\n",y[a-1]);
		}
	}
	return 0;
}