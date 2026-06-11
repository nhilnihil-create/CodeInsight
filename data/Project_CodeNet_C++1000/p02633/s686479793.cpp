#include<cstdio>
#include<iostream>
#include<algorithm>

using namespace std;

int read(){
	int x=0;
	char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
	return x;
}

int gcd(int a,int b) { return b?gcd(b,a%b):a; }
int lcm(int a,int b){
	int g=gcd(a,b);
	return a*b/g;
}

int main()
{
	int x=read();
	
	printf("%d\n",lcm(x,360)/x);
	
	return 0;
}