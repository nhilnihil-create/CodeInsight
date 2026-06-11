#include<bits/stdc++.h>
#define rep(i,j,k) for(int i=j;i<=k;i++)
#define rep2(i,j,k) for(int i=j;i>=k;i--)
#define mo 998244353
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
template<typename T> void chkmod(T &x,T y){x=(x+y>=mo)?(x+y-mo):(x+y);}
int co[3010];int dp[3010][3010];

int main(){
	int n,s;read(n);read(s);
	rep(i,1,n)read(co[i]);
	
	dp[0][0]=1;
	rep(i,1,n){
		rep2(j,s,0){
			int p=(2ll*dp[i-1][j])%mo;chkmod(dp[i][j],p);
			if(j>=co[i])chkmod(dp[i][j],dp[i-1][j-co[i]]);
		}
	}
	write(dp[n][s]);
	return 0;
}