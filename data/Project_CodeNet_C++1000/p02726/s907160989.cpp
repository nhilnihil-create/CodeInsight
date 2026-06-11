#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,x,y;
	cin>>n>>x>>y;
	x--;y--;
	ll ans[2010]={};
	for(ll i=0;i<n;i++){
		ll cnt[n]={};
		for(ll j=0;j<n;j++){
			cnt[j]=-1;
		}
		cnt[i]=0;
		queue<ll>q;
		q.push(i);
		while(q.size()!=0){
			ll now=q.front();
			q.pop();
			if(now!=0&&cnt[now-1]==-1){
				ll j=now-1;
				cnt[j]=cnt[now]+1;
				ans[cnt[j]]++;
				q.push(j);
			}
			if(now!=n-1&&cnt[now+1]==-1){
				ll j=now+1;
				cnt[j]=cnt[now]+1;
				ans[cnt[j]]++;
				q.push(j);
			}
			if(now==x&&cnt[y]==-1){
				ll j=y;
				cnt[j]=cnt[now]+1;
				ans[cnt[j]]++;
				q.push(j);
			}
			if(now==y&&cnt[x]==-1){
				ll j=x;
				cnt[j]=cnt[now]+1;
				ans[cnt[j]]++;
				q.push(j);
			}					
		}
	}
	for(ll i=1;i<n;i++){
		cout << ans[i]/2<<endl;
	}
	return 0;
}