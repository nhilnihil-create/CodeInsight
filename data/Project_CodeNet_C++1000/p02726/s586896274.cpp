#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,a,b;
	cin>>n>>a>>b;
	a--;b--;
	vector<ll>ch[2010];
	for(ll i=0;i<n-1;i++){
		ch[i].push_back(i+1);
		ch[i+1].push_back(i);
	}
	ch[a].push_back(b);
	ch[b].push_back(a);
	ll ans[2010]={};
	for(ll i=0;i<n;i++){
		ll cnt[2010];
		for(ll j=0;j<n;j++){
			cnt[j]=-1;
		}
		cnt[i]=0;
		queue<ll>q;
		q.push(i);
		while(q.size()!=0){
			ll now=q.front();
			q.pop();
			for(ll i=0;i<ch[now].size();i++){
				ll next=ch[now][i];
				if(cnt[next]!=-1){
					continue;
				}
				cnt[next]=cnt[now]+1;
				q.push(next);
			}
		}
		for(ll i=0;i<n;i++){
			ll now=cnt[i];
			ans[now]++;
		}
	}
	for(ll i=1;i<=n-1;i++){
		cout <<ans[i]/2<<endl;
	}
	return 0;
}