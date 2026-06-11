#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

ll n,ans[100010],ans1;
vector<pair<ll,ll>>ch[100010];
void dep(ll p,ll c){
	ll cnt=1;
	if(ch[p].size()==1&&p!=0){
		return ;
	}
	for(ll i=0;i<ch[p].size();i++){
		ll next=ch[p][i].first;
		ll noi=ch[p][i].second;
		if(ans[noi]!=0){
			continue;
		}
		if(cnt==c){
			cnt++;
		}
		ans[noi]=cnt;
		ans1=max(ans1,cnt);
		dep(next,cnt);
		cnt++;
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
	cout <<ans1<<endl;
	for(ll i=0;i<n-1;i++){
		cout << ans[i]<<endl;
	}
	// your code goes here
	return 0;
}