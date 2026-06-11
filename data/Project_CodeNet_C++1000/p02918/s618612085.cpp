#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define ge getchar 
#define pun putchar('\n')
#define pu putchar
#define puk putchar(' ')
char c,d;
int n,k,m,t,i;
ll g[50];
int sri(){c=ge();int x=0;while(c<'0')c=ge();while(c>='0')x=(x<<3)+(x<<1)+c-'0',c=ge();return x;}
void sc(ll x){int l=0;if(x==0)g[l=1]=0;while(x)g[++l]=x%10,x/=10;for(;l;l--)putchar(g[l]+'0');}
int main(){
	n=sri();k=sri();
	c=ge();while(c<'L')c=ge();d=c;m=1;t=0;
	for(i=2;i<=n;i++){
		c=ge();
		if(c==d)t++;else d=c,m++;
	}
	if(m&1){
		m>>=1;if(k>=m)t+=(m<<1);else t+=(k<<1);
	}else if(m>2){
		m>>=1;m--;if(k>m)t+=(m<<1)+1;else t+=(k<<1);
	}else if(k)t++;
	sc(t);
    return 0;
}