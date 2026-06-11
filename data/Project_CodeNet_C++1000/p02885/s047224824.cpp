#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	if(a - 2 * b >= 0){
		printf("%d",a - 2*b);
	}else{
		printf("%d",0);
	}
}