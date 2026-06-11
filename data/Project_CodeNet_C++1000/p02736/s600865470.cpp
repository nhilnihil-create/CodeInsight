#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
using namespace std;
template<typename T> void read(T &num){
	char c=getchar();T f=1;num=0;
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){num=(num<<3)+(num<<1)+(c^48);c=getchar();}
	num*=f;
}
template<typename T> void qwq(T x){
	if(x>9)qwq(x/10);
	putchar(x%10+'0');
}
template<typename T> void write(T x){
	if(x<0){x=-x;putchar('-');}
	qwq(x);putchar('\n');
}
int num[1000010];int dif[1000010];
int a[1000010];int b[1000010];

int main(){
	int n;read(n);
	rep(i,1,n){char ch;cin>>ch;num[i]=ch-'0';}
	rep(i,1,n-1)dif[i]=abs(num[i+1]-num[i]);
	rep(i,1,1000000)b[i]=((i%2==1)?0:(b[i/2]+1));
	
	if(n==1){write(num[n]);}
	else{
		rep(i,1,n)a[i]=num[i]%2;
		int ret=0;int ans=0;
		rep(i,1,n){ans+=(!ret)*a[i];ans%=2;ret+=b[n-i]-b[i];}
		if(ans%2==1){write(1);return 0;}
		
		int tmp=0;
		rep(i,1,n-1)tmp+=(dif[i]==1);
		if(tmp){write(0);return 0;}
		
		rep(i,1,n-1)a[i]=dif[i]/2;
		ret=0;ans=0;
		rep(i,1,n-1){ans+=(!ret)*a[i];ans%=2;ret+=b[n-1-i]-b[i];}
		write(2*(ans%2));
	}
	return 0;
}