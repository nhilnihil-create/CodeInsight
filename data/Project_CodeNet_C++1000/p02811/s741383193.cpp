#include<iostream>
#include<algorithm>

using namespace std;

int K,X;

int main(){
	scanf("%d%d",&K,&X);
	if(K*500<X) printf("No");
	else printf("Yes");
	return 0;
} 