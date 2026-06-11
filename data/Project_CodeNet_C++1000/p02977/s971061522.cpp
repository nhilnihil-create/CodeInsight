#include<iostream>
#include<cstdio>
using namespace std;
int n,L;
void o(int x,int y){cout<<x<<' '<<y<<'\n';}
int main(){
	scanf("%d",&n);
	if(n==(n&-n)) return puts("No"),0;
	puts("Yes");
	for(int i=2;i+1<=n;i+=2){
		o(i,i+1),o(i+1,1);
		o(1,n+i),o(n+i,n+i+1);
	}o(n+1,2);L=1<<31-__builtin_clz(n);
	if(!(n&1)) o(n,L+n),o(n+n,L^n^1);
}