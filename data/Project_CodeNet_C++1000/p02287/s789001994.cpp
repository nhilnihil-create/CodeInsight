#include<iostream>
#include<algorithm>
using namespace std;
#define Max 251

main(){
	int h,i,a[Max];
	scanf("%d",&h);
	for(i=1;i<=h;i++)
	scanf("%d",&a[i]);
	for(i=1;i<=h;i++){
		printf("node %d: key = %d, ",i,a[i]);
		if(i/2>0)
		printf("parent key = %d, ",a[i/2]);
		if(i*2<=h)
		printf("left key = %d, ",a[i*2]);
		if(i*2+1<=h)
		printf("right key = %d, ",a[i*2+1]);
		printf("\n");
		
	}
	return 0;
}

