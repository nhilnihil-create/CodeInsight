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
char S[110];int len[110];

int main(){
	scanf("%s",S+1);int n=strlen(S+1);int k;read(k);
	int cnt=0;long long ans=0;
	rep(i,1,n){
		if(S[i]!=S[i-1]){len[++cnt]=1;}
		else{len[cnt]++;}
	}
	if(cnt==1){ans=1ll*n*k/2;write(ans);return 0;}
	
	if(S[1]==S[n]){
		rep(i,1,cnt)ans+=len[i]/2;
		long long nop=0;len[cnt]+=len[1];
		rep(i,2,cnt)nop+=len[i]/2;
		nop*=k-1;ans+=nop;	
	}else{
		rep(i,1,cnt)ans+=len[i]/2;
		ans*=k;
	}
	write(ans);
	return 0;
}
