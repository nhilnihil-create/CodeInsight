#include<stdio.h>
#include<string.h>

typedef long long ll;			//ld.
typedef unsigned long long ull;	//llu.


int main(){
	int l,r,d;
	scanf("%d %d %d",&l,&r,&d);
	int sum  = 0;
	for(int i=l;i<=r;i++){
		if(i%d==0)
			sum+=1;
	}
	printf("%d\n",sum);
}