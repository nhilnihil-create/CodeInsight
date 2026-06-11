#include<bits/stdc++.h>
using namespace std;

int main(){
int s;
int a[]={500,100,50,10,5,1};
int b;
while(scanf("%d",&b),b){
	s=0;
	int c=1000-b;
	for(int d=0;d<6;d++){
		int e=c/a[d];
		s+=e;
		c-=e*a[d];
	}
	printf("%d\n",s);
}
}