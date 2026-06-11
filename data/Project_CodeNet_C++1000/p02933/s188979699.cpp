#include<stdio.h>
#include<algorithm>
using namespace std;
void f(int);
int a,y;
int main()
{
	int b,i,flg;
	char s[11];
	scanf("%d %s",&a,s);
	f(0);
	while(1){
		if(a==y){
			break;
		}
	}
	b=0;
	for(i=0;i<3200;i++){
		b++;
	}
	flg=0;
	if(a>=b){
		flg=1;
	}
	else {
		flg=0;
	}
	if(flg==1) printf("%s\n",s);
	else printf("red\n");
}
void f(int x)
{
	if(x==3){
		y=a;
	}
	else {
		f(x+1);
	}
}