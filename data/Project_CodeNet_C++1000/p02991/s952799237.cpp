#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define INF 1LL<<62
#define inf 1000000007

vector<ll>a[100010];
int main() {
	ll n,m;
	cin>>n>>m;
	for(ll i=0;i<m;i++){
		ll x,y;
		cin>>x>>y;
		x--;y--;
		a[x].push_back(y);
	}
	ll ch[100010][3];
	for(ll i=0;i<n;i++){
		for(ll j=0;j<3;j++){
			ch[i][j]=-1;
		}
	}
	ll s,e;
	cin>>s>>e;
	s--;e--;
	queue<pair<ll,ll>>q;
	ch[s][0]=0;
	q.push(make_pair(s,0));
	while(q.size()!=0){
		pair<ll,ll> now=q.front();
		//cout<< now.first<<now.second;
		q.pop();
		for(ll i=0;i<a[now.first].size();i++){
			ll next=a[now.first][i];
			if(ch[next][(now.second+1)%3]!=-1){
				continue;
			}
			ch[next][(now.second+1)%3]=ch[now.first][now.second]+1;
			q.push(make_pair(next,(now.second+1)%3));
		}
		//cout << "k"<<endl;
		//cout << ch[1][1];
	}
	if(ch[e][0]==-1){
		cout << -1;
	}
	else{
	cout << ch[e][0]/3;
	}
	// your code goes here
	return 0;
}