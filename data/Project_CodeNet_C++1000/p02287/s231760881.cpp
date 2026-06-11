#include<bits/stdc++.h>
using namespace std;
int H[256],h;
main(){
	scanf("%d",&h);
	for (int i=1;i<=h;i++)scanf("%d",&H[i]); 
	for (int i=1;i<=h;i++){
		printf("node %d: ",i);
		printf("key = %d, ",H[i]);
		if (i/2!=0) printf("parent key = %d, ",H[i/2]);
		if (i*2<=h) printf("left key = %d, ",H[i*2]);
		if (i*2+1<=h) printf("right key = %d, ",H[i*2+1]);
		printf("\n");
	}
}
