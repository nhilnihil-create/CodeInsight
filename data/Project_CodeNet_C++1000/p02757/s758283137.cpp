#include <stdio.h>
#include <map>
using namespace std;
char txt[200001];
int dp[2][10001];
int ddp[10001];
int main(){
	int N,P;scanf("%d %d\n",&N,&P);
	scanf("%s",txt);
	long long sum = 0;
	if(P<400){
		for(int i=0;i<N;i++){
		int nxt = i%2;
		int cnt=1-i%2;
		int d = txt[i]-'0';
		for(int j=0;j<P;j++) dp[nxt][j]=0;
		for(int j=0;j<P;j++){
			dp[nxt][(10*j+d)%P]+=dp[cnt][j];
		}
		dp[nxt][d%P]++;
		sum += dp[nxt][0];
		}
		printf("%lld",sum);
	}
	else{
		int cnt=0,p=1;
		for(int i=N-1;i>=0;i--){
			cnt=((txt[i]-'0')*p)%P + cnt;
			cnt%=P;
			ddp[cnt]++;
			p=(p*10)%P;
		}
		sum=ddp[0];
		for(int i=0;i<P;i++) sum+=1LL*ddp[i]*(ddp[i]-1)/2;
		printf("%lld",sum);
	}
}