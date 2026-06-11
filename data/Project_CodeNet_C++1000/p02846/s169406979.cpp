#include<cstdio>
#include<cstring>
#include<iostream>
#define in inline
#define re register
#define int long long
#define M 1000000007
using namespace std;
in int read() {
	re int t=0;
	re char v=getchar();	
	while(v<'0'||v>'9'){
	v=getchar();
	}	
	while(v>='0'&&v<='9'){		
	t=(t<<3)+(t<<1)+(v^48);		
	v=getchar();	}
	return t;
}
int t1,t2,a1,a2,b1,b2,a,b,lst,nxt,ans;
inline int gcd(re int x,re int y){
	return x%y?gcd(y,x%y):y;
}
signed main(){
t1=read();
t2=read();
a1=read();b1=read();
a2=read();

b2=read();

if((a1>a2&&b1>b2)||(a1<a2&&b1<b2)){
	puts("0");
	return 0;
}

if(a1<a2)swap(a1,a2),swap(b1,b2);
a=(a1-a2)*t1;
b=(b2-b1)*t2;
if(a>b){
	puts("0");
	return 0;
}
if(a==b){
	puts("infinity");
	return 0;
}
int tmp=b-a;
ans=(a/tmp)*2;
if(a%tmp)++ans;
printf("%lld",ans);
}
