#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 2e5;
int mod[N+100],cnt[10010];
char str[N+100];
ll ans;

int main()
{
	int n,p;
	scanf("%d%d%s",&n,&p,str);
	if(p==2){
		for(int i=n-1;i>=0;i--){
			if(((str[i]-'0')&1)==0){
				ans += (i+1);
			}
		}
	}
	else if(p==5){
		for(int i=n-1;i>=0;i--){
			if((str[i]-'0')==0||(str[i]-'0')==5){
				ans += (i+1);
			}
		}
	}
	else{
		mod[0] = 1;
		for(int i=1;i<=N;i++){
			mod[i] = (mod[i-1]*10)%p;
		}
		int cur = 0;
		cnt[0] = 1;
		for(int i=n-1;i>=0;i--){
			int t1 = (mod[n-1-i]*(str[i]-'0'))%p;
			cur = (cur+t1)%p;
			//printf("%d %d\n",i,cur);
			ans += cnt[cur];
			cnt[cur]++;
		}
	}
	printf("%lld\n",ans);
}
