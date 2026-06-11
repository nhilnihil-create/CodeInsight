#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
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
long long co[100010];long long mx[100010];

int main(){
	int n;read(n);
	rep(i,0,n)read(co[i]);
	
	if(n==0){write((co[0]==1)?1:-1);}
	else{
		if(co[0]){write(-1);return 0;}
		mx[0]=1;
		rep(i,1,n-1){
			mx[i]=mx[i-1]*2-co[i];
			if(mx[i]>400000000000000000)mx[i]=400000000000000000;
			if(mx[i]<1){write(-1);return 0;}
		}
		
		long long now=co[n];long long ans=co[n];
		rep2(i,n-1,0){
			if(now>mx[i]*2){write(-1);return 0;}
			now=min(now,mx[i]);now+=co[i];ans+=now;	
		}
		write(ans);
	}
	return 0;
}