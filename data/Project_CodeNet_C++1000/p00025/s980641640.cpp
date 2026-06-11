#include<stdio.h>
int main(){
	int a[4],b[4];
	while(~scanf("%d%d%d%d",&a[0],&a[1],&a[2],&a[3])){
		
		scanf("%d%d%d%d",&b[0],&b[1],&b[2],&b[3]);
		int hit=0,blow=0;
		if(a[0]==b[0])hit++;
		if(a[1]==b[1])hit++;
		if(a[2]==b[2])hit++;
		if(a[3]==b[3])hit++;
		if(a[0]==b[1])blow++;
		if(a[1]==b[2])blow++;
		if(a[2]==b[3])blow++;
		if(a[1]==b[0])blow++;
		if(a[2]==b[1])blow++;
		if(a[2]==b[0])blow++;
		if(a[3]==b[2])blow++;
		if(a[3]==b[1])blow++;
		if(a[3]==b[0])blow++;
		if(a[0]==b[2])blow++;
		if(a[1]==b[3])blow++;
		if(a[0]==b[3])blow++;
		printf("%d %d\n",hit,blow);
	}
}