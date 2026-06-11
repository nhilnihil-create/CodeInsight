#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

int main() {
	ll n,m;
	cin>>n>>m;
	vector<ll>ch[100010];
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		ch[x].push_back(y);
	}
	ll s,t;
	cin>>s>>t;
	s--;t--;
	queue<pair<ll,ll>>q;
	ll ans[100010][3];
	for(ll i=0;i<n;i++){
		for(ll j=0;j<3;j++){
			ans[i][j]=-1;
		}
	}
	q.push(make_pair(s,0));
	ans[s][0]=0;
	while(q.size()!=0){
		ll now=q.front().first;
		ll cnt=q.front().second;
		cnt++;
		q.pop();
		for(ll i=0;i<ch[now].size();i++){
			ll next=ch[now][i];
			if(ans[next][cnt%3]!=-1){
				continue;
			}
			ans[next][cnt%3]=cnt;
			q.push(make_pair(next,cnt));
		//	cout << now+1<< next+1<<endl;
		}
	//	cout<<endl;
	}
	if(ans[t][0]==-1){
		cout << -1;
		return 0;
	}
	cout <<ans[t][0]/3;
	// your code goes here
	return 0;
}