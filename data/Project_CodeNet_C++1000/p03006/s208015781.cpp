#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll MOD = 1e9 + 7;
const int inf = 1e9;
const ll INF = 1e18;
const double pi = 3.14159265358979323846;
#define rep(i,n) for(ll i=0;i<n;i++)

int main(){
	int n;cin>>n;
	pair<ll,int> p[n];
	rep(i,n) cin>>p[i].first>>p[i].second;
	map<pair<ll,int>,int> mp;
	
	rep(i,n){//すべてのパターンを試す(mpの中には合計n*(n-1)個入っているはず)
		rep(j,n){
			if(i!=j){
				pair<ll,int> q;
				q.first=p[j].first-p[i].first;
				q.second=p[j].second-p[i].second;
				mp[q]++;
			}
		}
	}
		
	int cnt=0;
	for(auto m:mp){
		cnt=max(m.second,cnt);
		//cout<<m.second<<"\n";
	}

	int ans=n-cnt;

	cout<<ans<<"\n";
}
