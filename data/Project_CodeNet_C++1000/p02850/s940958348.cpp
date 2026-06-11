#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007
 
ll n;
vector<pair<ll,ll>>ch[100010];
ll ans[100010],cnt;

void dep(ll now,ll c){
	ll nowc=1;
//	if(now!=0&&ch[now].size()==1){
//		return ;
//	}
	for(ll i=0;i<ch[now].size();i++){
		if(nowc==c){
			nowc++;
		}
		ll nex=ch[now][i].first;
		ll nexans=ch[now][i].second;
		if(ans[nexans]!=0){
			continue;
		}
		ans[nexans]=nowc;
		cnt=max(cnt,nowc);
		dep(nex,nowc);
		nowc++;
	}
}
int main() {
	cin>>n;
	for(ll i=0;i<n-1;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		ch[x].push_back(make_pair(y,i));
		ch[y].push_back(make_pair(x,i));
	}
	dep(0,0);
	cout <<cnt<<endl;
	for(ll i=0;i<n-1;i++){
		cout <<ans[i]<<endl;
	}
	// your code goes here
	return 0;
}