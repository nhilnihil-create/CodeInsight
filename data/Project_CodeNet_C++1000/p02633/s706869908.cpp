#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int gcd(int a,int b){
	if(!b)return a;
	return gcd(b,a%b);
}

int main(){
	int K;
	scanf("%d",&K);
	printf("%d\n",360/gcd(K,360));
	return 0;
}
